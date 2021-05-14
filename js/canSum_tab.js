// canSum(target, numbers)
// 
// canSum(7, [5,3,4]) -> true


function canSum(target, numbers) {
	const table = Array(target + 1).fill(false)
	table[0] = true

	for (let i=0; i<=target; i++) {
		// const current = table[i]	
		if (table[i])
		for (let num of numbers) {
			if (i + num <= target) {
				table[i+num] = true
			}
		}
	}
	return table[target]
}

console.log(canSum(7, [3, 4, 5]))
console.log(canSum(8, [3, 4, 5]))
console.log(canSum(10, [3, 4, 5]))
console.log(canSum(0, [3, 4, 5]))
console.log(canSum(300, [7, 14]))
