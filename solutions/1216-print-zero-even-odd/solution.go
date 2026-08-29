type ZeroEvenOdd struct {
    zeroChan chan struct{}
    oddChan  chan struct{}
    evenChan chan struct{}
	n        int
}

func NewZeroEvenOdd(n int) *ZeroEvenOdd {
	zeo := &ZeroEvenOdd{
		n:        n,
	}
    zeo.zeroChan = make(chan struct{}, 1)
    zeo.oddChan = make(chan struct{})
    zeo.evenChan = make(chan struct{})
    zeo.zeroChan <- struct{}{}
	return zeo
}

func (z *ZeroEvenOdd) Zero(printNumber func(int)) {
    for i := 1; i <= z.n; i++ {
        <- z.zeroChan
        printNumber(0)
        if i%2 == 1 {
            z.oddChan <- struct{}{}
        } else {
            z.evenChan <- struct{}{}
        }
    }
}

func (z *ZeroEvenOdd) Even(printNumber func(int)) {
    for i := 2; i <= z.n; i+=2 {
        <- z.evenChan
        printNumber(i)
        z.zeroChan <- struct{}{}
    }
}

func (z *ZeroEvenOdd) Odd(printNumber func(int)) {
    for i := 1; i <= z.n; i+=2 {
        <- z.oddChan
        printNumber(i)
        z.zeroChan <- struct{}{}
    }
}
