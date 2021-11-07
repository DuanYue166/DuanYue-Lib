import wordcloud

c=wordcloud.WordCloud(scale=12,font_path="msyh.ttc",background_color='white')

f=open("input.dat","r",encoding='utf-8')
s=f.read()
f.close()

c.generate(s)
c.to_file("out.png")