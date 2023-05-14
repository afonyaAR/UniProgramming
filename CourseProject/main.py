import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_absolute_error, mean_squared_error


# start settings
pd.set_option('display.width', 400)
pd.set_option('display.max_columns', 15)


# data info
# CP - себестоимость реализованной продукции
# NOE - средняя численность работников
# SOE - средняя зарплата работников
# PV - объем производства продукции
# PFS - прибыль от реализации продукции
# POP - рентабельность реализованной продукции
# POS - рентабельность продаж
# REV - выручка от реализации продукции
# REG - регион (regions)
# YER - год (2016 -2021)
# SIZ - размер (микроорганизация, малая орг-я, средняя орг-я)
# NP - чистая прибыль, убыток


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


# creating datafile
df = pd.DataFrame(dataset, columns=["CP", "NOE", "SOE", "PV", "PFS", "POP", "POS", "REV", "REG", "SIZ", "YER", "NP"])
le = LabelEncoder()
df["REG"] = le.fit_transform(df["REG"])
df["SIZ"] = le.fit_transform(df["SIZ"])


# datafile, EDA - exploratory data analysis,
print(df)
print(df.describe())


# correlation matrix
sns.set(font_scale=1.3)
plt.figure(figsize=(16, 10))
sns.heatmap(df.corr().round(2), annot=True, annot_kws={"size": 15})
plt.yticks(rotation=0)
plt.show()


# polynomial regression
X = df[["PFS", "REV", "POS", "SOE"]]
y = df["NP"]

polynomial = PolynomialFeatures(degree=2, include_bias=False)
poly_features = polynomial.fit_transform(X)

X_train, X_test, y_train, y_test = train_test_split(poly_features, y, test_size=0.2, random_state=42)

model = LinearRegression(fit_intercept=True)
model.fit(X_train, y_train)

predictions = model.predict(X_test)


# residual plot (poly)
sns.set(font_scale=2)
sns.set_style("white")
residuals = y_test - predictions
sns.scatterplot(x=y_test[0:100], y=residuals[0:100])
plt.axhline(y=0, color='r', linestyle='--')
plt.xlabel("NP")
plt.ylabel("Residual")
plt.title("Residual plot (poly)")
plt.show()


# calculating MAE, RMSE for polynomial regression
MAE = mean_absolute_error(y_test, predictions)
RMSE = np.sqrt(mean_squared_error(y_test, predictions))
print("MAE (poly): %f" % MAE)
print("RMSE (poly): %f" % RMSE)


# polynomial regression predict example
X_example = polynomial.fit_transform([[20000, 50000, 0.9, 900]])
print(model.predict(X_example))


# polynomial regression plot
sns.set(font_scale=1.5)
sns.set_style("white")
fig, axes = plt.subplots(2, 2)
df_show = df[0:100]
fig.suptitle("Polynomial regression")
sns.regplot(data=df_show, x="PFS", y="NP", order=2, ax=axes[0][0])
sns.regplot(data=df_show, x="REV", y="NP", order=2, ax=axes[0][1])
sns.regplot(data=df_show, x="POS", y="NP", order=2, ax=axes[1][0])
sns.regplot(data=df_show, x="SOE", y="NP", order=2, ax=axes[1][1])
plt.setp(axes, ylabel="NP")
plt.show()


# linear regression
X_lin = df["PFS"].values.reshape(-1, 1)
y_lin = df["NP"]

X_lin_train, X_lin_test, y_lin_train, y_lin_test = train_test_split(X_lin, y_lin, test_size=0.2, random_state=42)

lin_model = LinearRegression()
lin_model.fit(X_lin_train, y_lin_train)

linear_predictions = lin_model.predict(X_lin_test)


# residual plot (lin)
sns.set_style("white")
residuals = y_lin_test - linear_predictions
sns.scatterplot(x=y_lin_test[0:100], y=residuals[0:100])
plt.axhline(y=0, color='r', linestyle='--')
plt.xlabel("NP")
plt.ylabel("Residual")
plt.title("Residual plot (lin)")
plt.show()


# calculating MAE, RMSE for linear regression
MAE = mean_absolute_error(y_lin_test, linear_predictions)
RMSE = np.sqrt(mean_squared_error(y_lin_test, linear_predictions))
print("MAE (lin): %f" % MAE)
print("RMSE (lin): %f" % RMSE)


# linear regression predict example
X_lin_example = np.array([5, 10, 15, 2, 1]).reshape(-1, 1)
print(lin_model.predict(X_lin_example))


# linear regression plot
sns.set_style("white")
plt.figure(figsize=(10, 5))
sns.regplot(x=X_lin[0:100], y=y_lin[0:100])
plt.xlabel("PFS")
plt.ylabel("NP")
plt.title("Linear regression")
plt.show()
