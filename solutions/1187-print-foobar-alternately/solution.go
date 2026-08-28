type FooBar struct {
    turnChan chan struct{}
	n int
}

func NewFooBar(n int) *FooBar {
    f := FooBar{n: n}
    f.turnChan = make(chan struct{})
	return &f
}

func (fb *FooBar) Foo(printFoo func()) {
	for i := 0; i < fb.n; i++ {
		// printFoo() outputs "foo". Do not change or remove this line.
        printFoo()
        fb.turnChan <- struct{}{}
        <- fb.turnChan
	}
}

func (fb *FooBar) Bar(printBar func()) {
	for i := 0; i < fb.n; i++ {
        <-fb.turnChan
		// printBar() outputs "bar". Do not change or remove this line.
        printBar()
        fb.turnChan <- struct{}{}
	}
}
