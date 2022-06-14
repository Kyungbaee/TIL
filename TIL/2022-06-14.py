머신러닝 처리에 있어서 비지도학습, 지도학습 구별할 줄 알아야
→ cheat-sheet 전체적 흐름을 알고 있어야 한다
fit = 머신 러닝 과정에서 학습하는 것
fit으로 model 생성 -> prediction으로 test run 진행 -> evalution 과정(채점)

머신 러닝 전에 histogram 그려서 수치형, 범주형 중 어떤 데이터인지 대략적 파악 가능
(bins 갯수 조절하면서 확인)

columns명 중 예측할 데이터 = label_name
학습할 데이터 = features_names

예측치 100프로로 나오는 경우
1) 학습시킨 데이터와 test 데이터가 같음
2) feature_names에서 label_name 제거 안함

예측치 정확도 구할 때, data size 커지면 metrics 이용하여 구하는게 더 낫다

결정 트리 최상단 = importance가 가장 큰 피쳐값이 위치

gini 계수
1- ((T 비율)2) - ((F비율)2)
→ 0~0.5 사이 값으로 산출, 0에 가까울수록 확실하게 값이 나눠진 것

max_depth = 단계 너무 많으면 역시 오버피팅 발생
max_features = 전체 피쳐 대비 사용 정도, 적정선을 정해주면 오버피팅 방지해서 점수 증가
min_samples_split/min_samples_leaf/max_leaf_nodes = 너무 잘게 나누게 되면 오버피팅(=일반화 어려워짐)


Sciit-learn algorithm cheet sheet
Supervised Machine Learning Diagram => 학습과 예측 전체 과정
오늘 실습 메인 알고리즘: 결정 트리  DecisionTreeClassifier() + 파라미터 조정 => Accuracy 높이기
- overfitting: 학습을 너무 많이 해서 학습 데이터에만 너무 맞아서 일반화와의 generalization과의 괴리가 있음 - 예: max depth를 너무 깊게 지정한 경우
- underfitting: 학습을 적게함 - 예: max depth를 너무 적게 지정한 경우
- Feature Engineering: Garbage in Garbage out - Signal and Noise 구분하기 - Finding Signal is the key ⇒ How? EDA
- Data Preprocessing: Normalization, Outliers, Scaling, Imputation, Encoding
  
지니계수 - 얼마나 섞여있는지를 보여준다.
지니계수가 0이되면 트리를 멈춘다.
즉 0에 가까울 수록 섞여있는 것이 없고 순도가 높다.

과대 적합

적절하게 일반화하는 과정이 필요하기 때문에 깊이를 조절해 줄 필요가 있다.
train데이터의 점수는 높아져도 예측 데이터에는 부적합한 결과를 초래할 수 있다.

DecisionTreeClassifier 옵션

max_depth - 깊이 조절. 
max_depth에 따라서도 featureimportances가 달라질 수 있다.

max_features == 0.9라면 전체 feature의 90%만 사용한다.

X_train - 학습세트 y_train - 정답값

.fit(X_train, y_train) : 훈련

.predict(X_test) : 예측

예측의 정확도 측정 방법

1. (y_test == y_predict).mean()
2. model.score(X_test, y_test)

이상치와 결측치를 확인하고 전처리할 과정이 있다면 바꿔주면 좋다.

feature_names :컬럼을 리스트 형태로 저장

label_name : 정답값

X_train : feature_names 에 해당되는 컬럼만 train에서 가져옵니다.

X_test : feature_names 에 해당되는 컬럼만 test에서 가져옵니다.

y_train : label_name 에 해당 되는 컬럼만 train에서 가져옵니다.

model.fit(X_train, y_train) : 학습훈련

model.predict(X_test) : 예측
  
- 분류, 회귀, 군집화, 차원축소
- CART 알고리즘? 분류와 회귀에 모두 사용한 알고리즘을 뜻함
- 결정트리알고리즘 DecisionTreeClassifier
- gini, criterion,  max_depth, min_sample_split, min_sample_leaf, max_leaf_nods, max_features
- plot_tree() 결정트리 그림으로 출력
- model.featureimportances
- 과대적합, 과소적합

1. 지도학습
+ 지도 학습은 정답이 있음.
+ 종류
- 분류, 회귀
- 분류와 회귀 모두 할 수 있는 알고리즘 -> 트리 계열 알고리즘 가능, CART 알고리즘
+ 분류
- 범주형으로 분류할 수 있는 것들
- 예를 들면 스팸메일 인지 아닌지
+ sklearn.tree 에서 DecisionTreeClassifier
+ 과대적합은 공부는 했지만 일반화는 안된
+ 과소적합은 공부 덜 한 것 (데이터가 없는)
2. 비지도학습
- 클러스터링, 차원축소
3. 강화학습
4. 모델 만들기 -> Train -> Test 과정
5. model.fit(), model.score()

1. 인공지능 > 머신러닝 > 딥러닝 (머신러닝 알고리즘의 하나)
2. 머신러닝 = 지도학습 + 비지도학습 + 강화학습
3. 지도학습 : 라벨링된 정답이 있음 ⇒ 분류, 회귀
    1. 분류 classification - Decision tree 이용 시
        1. train/test data 분리
        2. feature/label 정보 분리
        3. X_train, y_train, X_test, y_train 
        4. 모델 fit (X_train, y_train) → predict (X_test)
        5. 트리 알고리즘 분석 : plot_tree from sklearn.tree
            1. model.featureimportances
            2. 정확도 측정 : accuracy_score(y_test, y_predict) or (y_predict == y_test).mean()
4. 비지도학습 : 정답 없음 ⇒ 군집화, 차원축소
  
<머신러닝 알고리즘 유형>

지도학습(정답 O) - 범주형 : 분류

지도학습(정답 O) - 수치형 : 회귀

비지도학습(정답 X) - 범주형 : 군집화

비지도학습(정답 X) - 수치형 : 차원축소

<지도학습 분류형 과정>

1. Training Data(X_train - 기출문제) + Traning Lables(y_train - 기출문제 정답)
- feature_names : 학습(훈련), 예측에 사용할 컬럼을 리스트 형태로 만들어서 변수에 담기
- label_name : 정답값
- X_train : feature_names 에 해당되는 컬럼만 train에서 가져오기
    - 학습(훈련)에 사용할 데이터셋 : 시험의 기출문제
- X_test : feature_names 에 해당되는 컬럼만 test에서 가져오기
    - 예측에 사용할 데이터셋 : 실전 시험문제
- y_train : label_name 에 해당 되는 컬럼만 train에서 가져오기
    - 학습(훈련)에 사용할 정답 값 : 기출문제의 정답
1. Model(머신러닝 알고리즘) : Fit - 주어진 자료와 정답으로 공부
- model = DecisionTreeClassifier(max_depth = 3, max_features=0.1)
    - DecisionTreeClasifier 파라미터
        - criterion : 가지의 분할의 품질을 측정하는 기능
        - max_depth : 트리의 최대 깊이
        - min_samples_split : 내부 노드를 분할하는 데 필요한 최소 샘플 수
        - min_samples_leaf : 리프 노드에 있어야 하는 최소 샘플 수
        - max_leaf_nodes : 리프 노드 숫자의 제한치
        - random_state : 추정기의 무작위성을 제어, 실행했을 때 같은 결과가 나오도록 함
1. Test Data(X_test - 실전문제) → Prediction : 기출문제와 정답을 바탕으로 X_test 풀어봄
- model.fit(X_train, y_train)
1. Test Labels(y_test - 실전문제의 정답=예측해야하는 값)
- y_predict = model.predict(X_test)
1. Evaluation : 제대로 문제를 풀었는지 채점
- 정확도 측정 알고리즘 : accuracy_score(y_test, y_predict)
- model score로 점수 계산 : model.score(X_test, y_test)

<의사결정나무>

- 분류와 회귀에 적용가능
- 지니계수 : 불순도 측정지표, 데이터의 분산정도를 정량화해서 표현한 값
  
