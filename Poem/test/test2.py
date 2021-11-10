# 可写函数说明
i=int(3)
def changeme():
	i=2
	def f2():
		nonlocal i
changeme()
print(i)

