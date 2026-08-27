type Foo struct {
    // channels
    doneFirst chan struct{}
    doneSecond chan struct{}
}

func NewFoo() *Foo {
	return &Foo{
        doneFirst: make(chan struct{}),
        doneSecond: make(chan struct{}),
	}
}

func (f *Foo) First(printFirst func()) {
	// Do not change this line
	printFirst()
    // Marking first done by closing channel
    close(f.doneFirst)
}

func (f *Foo) Second(printSecond func()) {
    // Blocking call
    <-f.doneFirst
	/// Do not change this line
	printSecond()
    // Marking second done by closing channel
    close(f.doneSecond)
}

func (f *Foo) Third(printThird func()) {
    // Blocking call
    <-f.doneSecond
	// Do not change this line
	printThird()
}
