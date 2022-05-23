import pandas as pd
from urllib import parse

class KBO:
    def __init__(self,team,year):
        self.team = parse.quote(f'{team}')
        self.year = year

    def kbo_hitter_page(self):
        base_url = f"http://www.statiz.co.kr/stat.php?opt=0&sopt=0&re=0&ys={self.year}&ye={self.year}&se=0&te={self.team}&tm=&ty=0&qu=auto&po=0&as=&ae=&hi=&un=&pl=&da=1&o1=WAR_ALL_ADJ&o2=TPA&de=1&lr=0&tr=&cv=&ml=1&sn=30&si=&cn="
        table = pd.read_html(base_url, encoding="UTF-8")
        if len(table[0]) > 22:
            table[0] = table[0].droplevel(axis=1,level=0).drop(index=[10,11,22,23])
        else :
            table[0] = table[0].droplevel(axis=1,level=0).drop(index=[10,11])
        df = table[0].iloc[:,:3]
        df2 = table[0].iloc[:,6:12]
        df3 = table[0].iloc[:,23:24]
        kbo_table = pd.concat([df,df2,df3],axis=1).dropna().drop(columns=["순"]).reset_index(drop=True)
        kbo_table.index += 1
        return kbo_table

    def kbo_Pitcher_page(self):
        base_url = f"http://www.statiz.co.kr/stat.php?opt=0&sopt=0&re=1&ys={self.year}&ye={self.year}&se=0&te={self.team}&tm=&ty=0&qu=auto&po=0&as=&ae=&hi=&un=&pl=&da=1&o1=WAR&o2=OutCount&de=1&lr=0&tr=&cv=&ml=1&sn=30&si=&cn="
        table = pd.read_html(base_url, encoding="UTF-8")
        if len(table[0]) > 22:
            table[0] = table[0].droplevel(axis=1,level=0).drop(index=[10,11,22,23])
        else : 
            table[0] = table[0].droplevel(axis=1,level=0).drop(index=[10,11])
        df = table[0].iloc[:,:3]
        df2 = table[0].iloc[:,7:12]
        df3 = table[0].iloc[:,23:27]
        kbo_table = pd.concat([df,df2,df3],axis=1).dropna().drop(columns=["순","보크","폭투"]).reset_index(drop=True)
        kbo_table.index +=1
        return kbo_table
    
def kbo_stats(team,year):
    kbo = KBO(team,year)
    hitter = kbo.kbo_hitter_page()
    pitcher = kbo.kbo_Pitcher_page()
    result = pd.concat([hitter,pitcher],axis=1)
    return result

print(["입력 양식 : 팀명 조회연도"])
print(["Example : KIA 2021 "])
print(["팀 선택 : KIA, 두산, 삼성, NC, 키움, SSG, 한화, LG, 롯데, KT"])
teaminfo = input().split()
team = teaminfo[0]
year = teaminfo[1]
display(kbo_stats(team,year))
