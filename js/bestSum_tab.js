// bestSum(targetSum, numbers)
//
// bestSum(8, [2, 3, 5]) -> [3, 5]

function bestSum(targetSum, numbers) {
	const table = Array(targetSum + 1).fill(null)
	table[0] = []

	for (let i=0; i <= targetSum; i++) {
		if (table[i])
			for (let num of numbers) {
				const minComb = [...table[i] , num]
				if (!table[i+num] || minComb.length < table[i+num].length)
					table[i + num] = minComb
			}
	}

	return table[targetSum]
}

console.log(bestSum(7, [4, 3]))
console.log(bestSum(15, [4, 3, 5]))
console.log(bestSum(10, [4, 3, 5]))
console.log(bestSum(12, [7, 5, 3, 4]))
console.log(bestSum(100, [1,2,5,25]))
