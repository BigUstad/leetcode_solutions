func maxProfit(prices []int) int {
    maxProfit := 0
    minPrice := int ((^uint(0)) >> 1)
    for _, p := range prices {
        if p < minPrice {
            minPrice = p
            // Deduct with other prices
            continue
        }
        if m := (p - minPrice); m > maxProfit {
            maxProfit = m
        }
    }
    return maxProfit
}
