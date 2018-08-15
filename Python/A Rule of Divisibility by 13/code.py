def dM(n):
	stringedN = str(n)
	nLength = len(stringedN)
	digits = []
	for k in range(nLength):
		stoi = [int(stringedN[k])]
		digits = digits + stoi
	return digits

def thirt(n):
#multiplicar, da direita pra esquerda de n, digitos por 1, 10, 9, 12, 3, 4
#somar essa putaria
#Repete isso ate o numero parar de mudar
	loucura(n)

def loucura(n):
	somaAtual = 0
	somaAntes = somaAtual - 1
	while somaAtual != somaAntes:
		somaAntes = somaAtual	
		digitos = dM(n)
		somaAtual = 0
		theList = [1, 10, 9, 12, 3, 4]
		i = 0
		usdDigits = list(reversed(digitos))
		for k in range(len(digitos)):
			somaAtual += usdDigits[k] * theList[i]
			i = i+1
			if i == 6:
				i = 0
		n = somaAtual
	print(somaAtual)