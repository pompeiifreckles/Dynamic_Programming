// canConstruct(target, wordBank) returns boolean indicating if
// target can be combination of concatednated strings in wordBank
// string re-use possible
//
// canConstruct(abcdef, [ab, abc, cd, def, abcd]) -> true
// canConstruct(skateboard, [ab, abc, cd, def, abcd]) -> false

// function canConstruct(target, wordBank) {
	// if (target == '') return true
	
	// for (let prefix of wordBank) {
		// const size = prefix.length	
		// if (target.slice(0, size) === prefix) {
			// if (canConstruct(target.slice(size), wordBank))
				// return true
		// }
	// }

	// return false
// }


function canConstruct(target, wordBank, memo = {}) {
	if (target in memo) return memo[target]
	if (target == '') return true
	
	for (let prefix of wordBank) {
		const size = prefix.length	
		if (target.slice(0, size) === prefix) {
			memo[target] = canConstruct(target.slice(size), wordBank, memo)
			if (memo[target]) return true
		}
	}

	return false
}


console.log(canConstruct('abc', ['a', 'bc']))
console.log(canConstruct('abcdef', ['abc', 'a', 'cd', 'bc', 'd', 'ef']))
console.log(canConstruct('skateboard', ['a', 'bc']))
console.log(canConstruct('skateboard', ['bo', 'rd', 'ate', 't', 'ska', 'sk', 'boar'])) // false
console.log(canConstruct('eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef', [
	'e', 
	'ee',
	'eee',
	'eeee',
	'eeeee',
	'eeeeee',
	// 'f'
]))
