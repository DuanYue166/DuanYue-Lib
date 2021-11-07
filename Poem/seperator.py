import jieba

def abandon_words(list):
	f=open("abandoned.txt","r",encoding='utf-8')
	banned=['','\n',' ','\t']
	banned.extend(f.read().split())
	# print("ban:",banned)
	for x in list:
		if(x in banned):
			while(x in list):
				list.remove(x)

def unique(list):
	out=[]
	for x in list:
		if(x not in out):
			out.append(x)
	return out

f_in=open("poems.dat","r",encoding='utf-8')

wordList=[]
for line in f_in.read().split():
	wordList.extend(jieba.lcut(line,cut_all=True))
f_in.close()

abandon_words(wordList)

cnt={}
for x in wordList:
	cnt[x]=0
for x in wordList:
	cnt[x]=cnt[x]+1

wordList.sort(key=lambda x:-cnt[x])
wordList=unique(wordList)

f_out=open("words_noNum.dat","w",encoding='utf-8')

for x in wordList:
	f_out.write('{}\n'.format(x))


f_out.close()