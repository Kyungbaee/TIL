# 필요한 라이브러리 불러오기
import pandas as pd
import plotly.express as px

# 2014-2020년 강력범죄(폭력) 데이터 불러오기 및 전처리
df = pd.read_csv("파일이름.csv",encoding="cp949").iloc[:,:-1]
df = df[df["발생지역별"] != "계"]

# 폭력 범죄 건수와 지역별 인구 수집
population = df[df["범죄별"] == "인구(B)"]
crime = df[df["범죄별"] == "강력범죄(폭력)"]

# 폭력 범죄 건수와 지역별 인구 전처리
num_pop = population.iloc[:,4:]
num_crime = crime.iloc[:,4:]

# 지역별 범죄율 = 범죄 건수 / 지역별 인원 * 100으로 수치화
num_crime = num_crime.astype("float")
num_pop = num_pop.astype("float")
ratio_list = [num_crime.iloc[i] / num_pop.iloc[i] * 100 for i in range(len(num_pop))]

# 지역별 범죄율 데이터프레임 생성 및 컬럼, 인덱스 수정
ratio_list_df = pd.DataFrame(ratio_list, columns=num_crime.columns)
crime_df = pd.DataFrame(crime["발생지역별"]).reset_index(drop=True)
ratio_table = pd.concat([ratio_list_df,crime_df],axis=1).set_index("발생지역별")

# 히트맵으로 시각화
px.imshow(ratio_table.T,width=800,title="2014년~2020년 전국 걍력범죄(폭력) 범죄율")
