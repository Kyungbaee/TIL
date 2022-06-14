- glob
- 필요없는 데이터 및 컬럼 삭제로 메모리 줄이기
- melt
- pd.to_numeric
        errors
                1) coerce = 숫자로 바꿀 수 없는 것은 Null값으로 변환
                2) ignore = 숫자로 바꿀 수 없는 것은 무시하고 그냥 둠
- pivot_table
- apply
- sns.barplot, sns.pointplot, sns.boxplot, sns.swarmplot, sns.violinplot
- lineplot(수치형)과 pointplot(범주형)의 차이
- Kosis 데이터
- columns rename

long-form, wide-form
wide form 데이터에서는 변수 사용이 어렵기 때문에 melt를 이용해 long-form으로 바꿔준다.
to_numeric(errors='coerce')
isin()
loc[:, cols] 
melt

- 결측치  구하기 : df.isnull(), df.isna()
- 데이터 타입 변경 : pd.to_numeric(df[ ], errors=’coerce’)
- df[”연도”].astype(str) 을 통해 수치 데이터를 문자 데이터로 변환
- axis 0 = 행, axis 1 = 열
- df_melt : 데이터 병합시 열에 있는 데이터 행으로 이동
- df.split(”년”) : ‘년'을 기준으로 텍스트 분리
- df.columns.tolist : 컬럼명을 리스트로 만들 때 tolist 사용
- type(df[’암검진별']) : ‘암검진별' type확인
- .loc : 서브셋 가져오기
- Boolean indexing : true, false로 반환
- and : &, or : |
          
melt - 열에 있는 데이터를 행으로 녹인다.
.str.replace(x, y) - str x값을 y로 바꿔준다.
.apply(함수) - 함수를 적용해서 데이터프레임에 바로 적용시켜준다.
.concat() - 옵션 지정해 주지 않으면 axis=0
df.groupby(["인덱스로 사용할 컬럼명"])["계산할 컬럼 값"].연산()
pairplot
sns.heatmap(데이터, cmap="색상",  annot=bool, fmt=bool)
sns.pointplot -> 범주형 / sns.lineplot -> 수치형
sns.boxplot,violin,swarm (data=df, x=, y=)
          
캐글, 데이콘을 통해 남의 코드 많이 보기
wide-form, long-form
깔끔한 데이터란? 각 변수가 열이고, 각 관측치가 행이 되도록 배열된 데이터
variable == 변수
오늘의 목표 == 전혀 다른 데이터를 합쳐서 분석하기!
씨본과 px는 롱폼의 데이터를 시각화하기 좋다
판다스 플롯은 와이드폼 데이터를 시각화하기 좋음.
import glob
glob.glob("data/*") - 파일 저장경로를 알 수 있음.
분양가격에 결측치가 많은 이유는 특정지역, 시기, 규모에 해당하는 분양내역이 없어서 이다.
매달 분양이 나는건 아니닌까
strip은 빈문자열을 바꾸기?
coerce는 강제로 형태 바꾸기
도메인지식이 중요한 것 같다.
.str.replace("ooo", "", regex = True)
대각선은 자기 자신
공공데이터가 대부분 수치데이터인 이유는 용량을 줄이기 위해서이다.
estimator????
ci = 신뢰구간 (confidence interval)
annot=True는 각 셀에 숫자를 표기한다.
kosis 행렬전환 기능으로 판다스에서 melt 굳이 안해도 됨.
parquet은 열로 저장해서 용량이 줄어듬.
데이터프레임이란 표형태의 데이터
         
- lineplot과 pointplot은 형태가 유사하지만, 수치형/범주형 데이터를 다룬다는 차이가 있음
- int에도 int8/32/64 등 다양한 타입이 존재하고, 이에 따라서 메모리 사용량이 달라질 수 있다
- 분석하기 좋은 데이터 : Tidy data
- 데이터에는 크게 wide-form/long-form이 있음 : 이 중 long- 이 tidy data에 해당
-  wide-form 데이터를 long-form으로 변형하기 위해 melt method를 사용가능
- 필요없는 데이터 행을 삭제할 땐, drop() / del 사용 가능
- heatmap에서 annot= True를 통해 표기한 값이 과학적 표기법에 의해 너무 더러워 보일 경우, fmt 인자를 통해 포맷을 지정해줄 수 있음
          
<Long-form / Wide-form>
seaborn, plotly: Long-form 형태의 데이터가 시각화하기에 좋다
pandas: Wide-form 형태의 데이터가 시각화하기에 좋다
<Tidy Data>
- 각 변수는 개별의 열(column)으로 존재하며 관측치는 행(row)을 구성한다.
- 각 표는 단 하나의 관측 기준에 의해서 조직된 데이터를 저장한다.
- 만약 여러 개의 표가 존재한다면, 적어도 하나 이상의 열(column)이 공유되어야 한다
< string-handling >
- 문자열을 정수값으로 표현한다거나 원하는 형태로 바꿈
- 판다스 문서 참조
<concat>
- 여러개의 데이터 프레임 합치기
- 잘합쳐졌는지 확인 해야함!
<group by>
- 데이터 집계하기
- 원하는 기준을 세우고 데이터 확인하기
          
to_numeric:  공백있는 object타입을 숫자 자료형으로 변경하여 반환합니다.
wide / long data와 melt: Hadley Wickham 교수의 논문에는 wide보다는 long data가 tidy data(깔끔한 데이터)라고 설명합니다. melt를 사용해 long data를 만들 수 있습니다.
숫자만 되어있는 공공데이터: 데이터의 크기를 줄이기 위함입니다.
barplot의 ci: confidence interval 신뢰구간입니다.
pointplot과 lineplot: pointplot은  범주형 그래프이고 lineplot 수치형 그래프입니다. 만약 pointplot으로 그려지는데 lineplot으로 안그려지는게 있다면 데이터가 수치형 데이터가 아니라서 그릴 수 없는 것 입니다.
pairplot: 데이터 세트에서 2쌍으로 플로팅합니다.
