// howSum(targetSum, numbers)
//
// howSum(7, [5,3,4]) -> [4,3]

function howSum(targetSum, numbers) {
	const table = Array(targetSum + 1).fill(null)
	table[0] = []

	for (let i=0; i <= targetSum; i++) {
		if (table[i] !== null)
			for (let num of numbers) {
				if (i + num <= targetSum)
					table[i + num] = [...table[i], num]
			}
	}

	return table[targetSum]
}

console.log(howSum(7, [3, 4, 5]))
console.log(howSum(8, [3, 4, 5]))
console.log(howSum(7, [2, 4]))
console.log(howSum(13, [3, 4, 5]))
console.log(howSum(300, [7, 14]))
