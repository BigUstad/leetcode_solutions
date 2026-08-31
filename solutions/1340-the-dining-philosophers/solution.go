type DiningPhilosophers struct {
    forks [5]bool
    fCond *sync.Cond
    fMu sync.Mutex
    fInit sync.Once
}

func (this *DiningPhilosophers) wantsToEat(
    philosopher int,
    pickLeftFork func(),
    pickRightFork func(),
    eat func(),
    putLeftFork func(),
    putRightFork func(),
) {
    this.fInit.Do(func() {
        for i := 0; i < len(this.forks); i++ {
            this.forks[i] = true
        }
        this.fCond = sync.NewCond(&this.fMu)
    })
    // The complete implementation of the algo:
    i := philosopher
    j := (i + 1) % 5
    // Check if left & right forks are available.
    // If not wait till they are available
    this.fMu.Lock()
    for !this.forks[i] || !this.forks[j] {
        this.fCond.Wait()
    }
    // fmt.Print(philosopher)
    // fmt.Print(").")
    // fmt.Println(this.forks)
    // Mark as unavailable
    this.forks[i] = false
    this.forks[j] = false
    // fmt.Print(philosopher)
    // fmt.Print(").")
    // fmt.Println(this.forks)
    // No need to lock for eat
    this.fMu.Unlock()
    // Execute eat
    pickLeftFork()
    pickRightFork()
    eat()
    putRightFork()
    putLeftFork()
    // Lock to update forks status to available
    this.fMu.Lock()
    this.forks[i] = true
    this.forks[j] = true
    // Broadcast to say forks are available
    this.fCond.Broadcast()
    this.fMu.Unlock()
}

