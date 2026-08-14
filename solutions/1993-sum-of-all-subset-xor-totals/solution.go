// Gemini solution
/*
Why this saves massive memoryZero Allocations: No slice headers are built, and no heap copies are ever triggered. The memory footprint stays absolutely flat.Stack Efficiency: Passing raw integers (int) down recursive call frames is incredibly fast and highly optimized by the Go compiler, keeping your execution cache perfectly clean.

There is a fascinating mathematical property hidden in this problem. If you look at every bit position across all subsets, every single element contributes to exactly half of the total \(2^{n}\) subsets. This means you can bypass backtracking and recursion completely with a single bitwise OR loop:

func subsetXORSum(nums []int) int {
    bits := 0
    for _, num := range nums {
        bits |= num // Collect all bits present across all numbers
    }
    // Multiply by 2^(n-1) using a left bitwise shift
    return bits << (len(nums) - 1)
}

*/

func subsetXORSum(nums []int) int {
    n := len(nums)
    if n == 0 {
        return 0
    }

    totalSum := 0

    var backtrack func(start int, currentXOR int)
    backtrack = func(start int, currentXOR int) {
        // Add the XOR total of the current subset to our global total
        totalSum += currentXOR

        // Explore further subsets by including remaining elements
        for i := start; i < n; i++ {
            // Calculate the next running XOR value on the fly
            backtrack(i+1, currentXOR ^ nums[i])
        }
    }

    // Start backtracking with the first index and an initial XOR sum of 0
    backtrack(0, 0)

    return totalSum
}

