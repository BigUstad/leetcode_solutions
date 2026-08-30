type H2O struct {
    mu sync.Mutex
    cond *sync.Cond
    hCount int
}

func NewH2O() *H2O {
	h := &H2O{}
    h.cond = sync.NewCond(&h.mu)
    h.hCount = 0
	return h
}

func (h *H2O) Hydrogen(releaseHydrogen func()) {
    h.mu.Lock()
    defer h.mu.Unlock()
    for h.hCount == 2 {
        // 2H. Wait for O & release
        h.cond.Wait()
    }
	// releaseHydrogen() outputs "H". Do not change or remove this line.
	releaseHydrogen()
    h.hCount++
    // 2H. Tell O to form bond & Release
    if h.hCount == 2 {
        h.cond.Broadcast()
    }
}

func (h *H2O) Oxygen(releaseOxygen func()) {
    h.mu.Lock()
    defer h.mu.Unlock()
    for h.hCount < 2 {
        h.cond.Wait()
    }
	// releaseOxygen() outputs "H". Do not change or remove this line.
	releaseOxygen()
    h.hCount = 0
    h.cond.Broadcast()
}
