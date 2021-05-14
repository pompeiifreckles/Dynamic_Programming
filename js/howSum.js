// howSum(targetSum, numbers), find targetSum by sum of elements in array
// howSum(targetSum, numbers) -> null, if no possible combination
// howSum(targetSum, numbers) -> combination, if there are combinations


function howSum(targetSum, numbers, memo = {}) {
	if (targetSum in memo) return memo[targetSum]
	if (targetSum === 0) return []
	if (targetSum < 0) return null

	for (let num of numbers) {
		const remainder = targetSum - num
		const remainderResult = howSum(remainder, numbers, memo)
		if (remainderResult !== null) {
			memo[targetSum] = [...remainderResult, num]
			return memo[targetSum]
		}
	}

	memo[targetSum] = null
	return null
}

// console.dir(howSum(7, [2, 3]))
// console.dir(howSum(7, [5, 3, 4, 7]))
// console.dir(howSum(7, [2, 4]))
console.dir(howSum(8, [2, 3, 5]))
console.dir(howSum(300, [7, 14]))
