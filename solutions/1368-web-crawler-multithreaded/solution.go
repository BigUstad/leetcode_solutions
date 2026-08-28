import (
    "math/rand"
    "time"
)

/*
Runtime 44ms 20.88%
Memory 9.68mb 89.01%
*/
/*
 This is HtmlParser's API interface.
 You should not implement it, or speculate about its implementation
    type HtmlParser struct {
        maps  map[string]int
        imaps map[int]string
        a     map[int][]int
    }
*/
// func getHost(u string) string {
//     p,_ := url.Parse(u)
//     return p.Hostname()
// }

// Helper function to extract hostname safely
func getHost(url string) string {
    // Trim "http://" prefix
    if len(url) > 7 && url[:7] == "http://" {
        url = url[7:]
    }
    // Handle "https://" variant if encountered
    if len(url) > 8 && url[:8] == "https://" {
        url = url[8:]
    }
    // Isolate path endpoints
    if idx := strings.IndexByte(url, '/'); idx != -1 {
        url = url[:idx]
    }
    return url
}

func crawl(startUrl string, htmlParser *HtmlParser) []string {
    resSl := []string{startUrl}
    visited := make(map[string]bool)
    visited[startUrl] = true
    workerCount := 4
    urlsCh := make(chan string, 100)
    resUrlsCh := make(chan []string, 100)
    u, _ := url.Parse(startUrl)
    targetHost := u.Hostname()
    var wg sync.WaitGroup

    for i:=0; i < workerCount; i++ {
        // fmt.Print("Starting worker ")
        // fmt.Println(i)
        wg.Add(1)
        go func(workerID int) {
            defer wg.Done()
            for url := range urlsCh {
                retUrls := htmlParser.GetUrls(url)
                // fmt.Print("worker ")
                // fmt.Print(i)
                // fmt.Print(" got urls of len: ")
                // fmt.Println(len(retUrls))
                resUrlsCh <- retUrls
            }
        }(i)
    }
    urlsCh <- startUrl
    activeWorkers := 1
    for activeWorkers > 0 {
        resUrls := <- resUrlsCh
        activeWorkers--
        // // fmt.Print("resUrls ch returned count: ")
        // // fmt.Println(len(resUrls))
        // // fmt.Println(resUrls)
        for _, r := range resUrls {
            if getHost(r) == targetHost && !visited[r] {
                visited[r] = true
                resSl = append(resSl, r)
                // fmt.Print("Adding: ")
                // fmt.Println(r)
                activeWorkers++
                urlsCh <- r
            }
        }
    }
    close(urlsCh)
    wg.Wait()
    // fmt.Print("final sl: ")
    // fmt.Println(len(resSl))
    close(resUrlsCh)
    return resSl
}
