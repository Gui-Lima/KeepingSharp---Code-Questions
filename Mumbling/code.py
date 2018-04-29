#accum("abcd")     "A-Bb-Ccc-Dddd"
#accum("RqaEzty")  "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
#accum("cwAt")     "C-Ww-Aaa-Tttt"


def accum(s):
	length = len(s)
	result = ""
	for k in range(length):
		s = s.lower()
		upperCased = s.upper()
		result += upperCased[k]
		result += s[k] * k
		if k != length -1:
			result += "-"
	return result


