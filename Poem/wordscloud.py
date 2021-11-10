import wordcloud

f=open("words_two_noNum.dat","r",encoding='utf-8')
wordList=[line.strip() for line in f.readlines()]
f.close()

WC=wordcloud.WordCloud(max_words=100,font_path='msyh.ttc',background_color='white',\
                       max_font_size=2200,min_font_size=200,font_step=20,\
                       width=6400,height=3200,scale=4)
WC.generate(" ".join(wordList))
WC.to_file("out2.png")
