import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_absolute_error, mean_squared_error


# data info
# CP - себестоимость реализованной продукции
# NOE - средняя численность работников
# SOE - средняя зарплата работников
# PV - объем производства продукции
# PFS - прибыль от реализации продукции
# POP - рентабельность реализованной продукции
# POS - рентабельность продаж
# REV - выручка от реализации продукции
# NP - чистая прибыль, убыток
# REG - регион (regions)
# YER - год (2016 -2021)
# SIZ - размер (микроорганизация, малая орг-я, средняя орг-я)


# importing datasets
keep_cols = [i for i in range(1, 19)]
df_CP = pd.read_excel("cost_price_X.xls", usecols=keep_cols).to_numpy()
df_NOE = pd.read_excel("number_of_employees_X.xls", usecols=keep_cols).to_numpy()
df_SOE = pd.read_excel("salary_of_employees_X.xls", usecols=keep_cols).to_numpy()
df_PV = pd.read_excel("production_volume_X.xls", usecols=keep_cols).to_numpy()
df_PFS = pd.read_excel('profit_from_sales_X.xls', usecols=keep_cols).to_numpy()
df_POP = pd.read_excel("profitability_of_products_sold_X.xls", usecols=keep_cols).to_numpy()
df_POS = pd.read_excel("profitability_of_sales_X.xls", usecols=keep_cols).to_numpy()
df_REV = pd.read_excel("revenue_X.xls", usecols=keep_cols).to_numpy()
df_NP = pd.read_excel("net_profit_Y.xls", usecols=keep_cols).to_numpy()
df_REG = ["Белыничский", "Бобруйский", "Быховский", "Глусский",
          "Горецкий", "Дрибинский", "Кировский", "Климовичский",
          "Кличевский", "Костюковичский", "Кричевский", "Круглянский",
          "Могилевский", "Мстиславский", "Осиповичский", "Славгородский",
          "Хотимский", "Чаусский", "Чериковский", "Шкловский",
          "г. Могилев", "г. Бобруйск"]
df_SIZ = ["micro", "small", "medium"]
df_YER = [2016, 2017, 2018, 2019, 2020, 2021]


# creating new dataset
dataset = []
for region in range(len(df_REG)):
    additional_info = [df_REG[region]]

    for size in range(len(df_SIZ)):
        additional_info.append(df_SIZ[size])

        for year in range(len(df_YER)):
            additional_info.append(df_YER[year])
            coord = (region, year+size*6)
            row = [df_CP[coord], df_NOE[coord], df_SOE[coord], df_PV[coord],
                   df_PFS[coord], df_POP[coord], df_POS[coord], df_REV[coord],
                   *additional_info, df_NP[coord]]

            dataset.append(row)

            additional_info.pop(2)

        additional_info.pop(1)

    additional_info.pop(0)


df = pd.DataFrame(dataset, columns=["CP", "NOE", "SOE", "PV", "PFS", "POP", "POS", "REV", "REG", "SIZ", "YER", "NP"])
le = LabelEncoder()

df["REG"] = le.fit_transform(df["REG"])
df["SIZ"] = le.fit_transform(df["SIZ"])

X = df[["PFS", "REV", "POS", "SOE"]]
y = df["NP"]

polynomial = PolynomialFeatures(degree=2, include_bias=False)
poly_features = polynomial.fit_transform(X)

X_train, X_test, y_train, y_test = train_test_split(poly_features, y, test_size=0.2, random_state=42)

model = LinearRegression(fit_intercept=True)
model.fit(X_train, y_train)

predictions = model.predict(X_test)

MAE = mean_absolute_error(y_test, predictions)
MSE = mean_squared_error(y_test, predictions)
RMSE = np.sqrt(MSE)

print("MAE: %f" % (MAE))
print("RMSE: %f" % (RMSE))

X_temp = [[200000, 250000, -1, 1500]]
print(model.predict(polynomial.fit_transform(X_temp)))

# correlation matrix
# plt.figure(figsize=(16,10))
# sns.heatmap(df.corr(), annot=True)
# plt.show()

# residual plot (precise)
# residuals = y_test - predictions
# sns.scatterplot(x=y_test, y=residuals)
# plt.axhline(y=0, color='r', linestyle='--')
# plt.xlabel("Net profit")
# plt.ylabel("Residuals")
# plt.title("Residual Plot")
# plt.show()
