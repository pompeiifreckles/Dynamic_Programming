// bestSum(targetSum, numbers) returns shortes combination
// of numbers that add upto targetSum
//
// bestSum(7, [5, 3, 4, 7]) -> [7]
// bestSum(8, [2, 3, 5]) -> [3, 5]

function bestSum(targetSum, numbers, memo = {}) {
	if (targetSum in memo) return memo[targetSum]
	if (targetSum === 0) return []
	if (targetSum < 0) return null

	let shortestComb = null

	for (let num of numbers) {
		const remainder = targetSum - num
		const remainderComb = bestSum(remainder, numbers, memo)

		if (remainderComb !== null) {
			const combination = [...remainderComb, num]
			if (shortestComb === null || combination.length < shortestComb.length) {
				shortestComb = combination
			}
		}		
	}

	memo[targetSum] = shortestComb
	return memo[targetSum]
}

console.log(bestSum(7, [5, 3, 4, 7]))
console.log(bestSum(8, [2, 3, 5]))
console.log(bestSum(300, [2, 3, 5]))
// console.log(bestSum(8, [2]))
