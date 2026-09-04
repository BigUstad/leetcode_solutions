type DiningPhilosophers struct {
    philInit sync.Once
}

const (
    Eat = iota
    Done
    GoAhead
)
type DiningRequest struct {
    philosopher int
    signal int
}

type Coordinator struct {
    forks [5]bool
    queue *list.List
    doneCh chan struct{}
}

// Single Public request channel where all philosophers send signals
// Request to eat. Signal done eating.
// 5 private response channels where the coordinator tells yes or no.
var (
    co *Coordinator
    fInit sync.Once
    reqCh chan DiningRequest
    respCh [5]chan int
)

// GetCoordinator is the global entry point for all goroutines
func GetCoordinator() *Coordinator {
    // sync.Once guarantees the inner function runs EXACTLY once,
    // blocking all other goroutines until the initialization completes.
    fInit.Do(func() {
        // fmt.Println("GetCoordinator()")
        co = &Coordinator{}
        for i := range co.forks {
            co.forks[i] = true
            respCh[i] = make(chan int, 1)
        }
        reqCh = make(chan DiningRequest, 5)
        co.queue = list.New()
        co.doneCh = make(chan struct{})
        // for i := 0; i < 5; i++ {
        //     if i % 2 == 0 {
        //         respCh[i] <- DoWait
        //     } else {
        //         respCh[i] <- Eat
        //     }
        // }
        go co.processDiningRequest()
    })

    return co
}
// fork indices i, j
func (c *Coordinator) processEat(req DiningRequest) {
    i := req.philosopher
    j := (i + 1) % 5
    // fmt.Println(c.forks)
    if !c.forks[i] || !c.forks[j] {
        c.queue.PushBack(req)
    } else {
        c.forks[i] = false
        c.forks[j] = false
        respCh[i] <- GoAhead
    }
}
func (c *Coordinator) processQueue() {
    if c.queue.Len() == 0 {
        return
    }
    req := c.queue.Front().Value.(DiningRequest)
    c.processEat(req)
    c.queue.Remove(c.queue.Front())
}

func (c *Coordinator) processDiningRequest() {
    // fmt.Println("processDiningRequest()")
    for {
        select {
            case request := <-reqCh:
                i := request.philosopher
                j := (i + 1) % 5

                switch request.signal {
                case Eat:
                    c.processEat(request)
                case Done:
                    c.forks[i] = true
                    c.forks[j] = true
                    c.processQueue()
                }
            case <-c.doneCh:
                return
        }
        // time.Sleep(1 * time.Microsecond)
    }
}

func (c *Coordinator) Close() {
    close(c.doneCh)
}

func (this *DiningPhilosophers) wantsToEat(
    philosopher int,
    pickLeftFork func(),
    pickRightFork func(),
    eat func(),
    putLeftFork func(),
    putRightFork func(),
) {
    this.philInit.Do(func() {
        // fmt.Println("one Init")
        GetCoordinator()
    })
    // The complete implementation of the algo:
    //  No need to do it in a for loop as the caller takes care of it
    // 1. Request on public channel
    // 2. Wait for response on private channel
    // 3. Tell done on public channel

    // Requesting with philosopher id & with signal to wanting to eat
    req := DiningRequest{philosopher: philosopher, signal: Eat}
    // // fmt.Println(req)
    reqCh <- req
    // Waiting on private response channel for coordinator to respond
    // If signal says wait, try again later
    sig := <- respCh[philosopher]

    if sig == GoAhead {
        // Coordinator has marked the forks unavailable.
        // Executing eat
        pickLeftFork()
        pickRightFork()
        eat()
        putLeftFork()
        putRightFork()
    }
    // Coordinator will mark forks unavailable
    reqCh <- DiningRequest{philosopher: philosopher, signal: Done}
}

