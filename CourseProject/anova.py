import pandas as pd
from math import sqrt
from random import sample, Random


def normalization(samples):
    mx = sum(samples) / len(samples)
    dx = sum(i ** 2 for i in samples) / len(samples) - mx ** 2
    sigma = sqrt(dx)
    return [(i - mx) / sigma for i in samples]


# pandas settings
pd.set_option('display.width', 400)
pd.set_option('display.max_columns', 15)


# data info
# SIZ - размер (микроорганизация, малая орг-я, средняя орг-я)
# NP - чистая прибыль, убыток


# importing datasets
keep_cols = [i for i in range(1, 19)]
# df_NP = pd.read_excel("net_profit_Y.xls", usecols=keep_cols).to_numpy()
df_NP = pd.read_excel("profit_from_sales_X.xls", usecols=keep_cols).to_numpy()
df_REG = ["Белыничский", "Бобруйский", "Быховский", "Глусский",
          "Горецкий", "Дрибинский", "Кировский", "Климовичский",
          "Кличевский", "Костюковичский", "Кричевский", "Круглянский",
          "Могилевский", "Мстиславский", "Осиповичский", "Славгородский",
          "Хотимский", "Чаусский", "Чериковский", "Шкловский",
          "г. Могилев", "г. Бобруйск"]
df_SIZ = ["m", "s", "M"]
df_YER = [2016, 2017, 2018, 2019, 2020, 2021]

# datasets creating
micro = []
small = []
medium = []
for region in range(len(df_REG)):
    for size in range(len(df_SIZ)):
        for year in range(len(df_YER)):
            coord = (region, year+size*6)
            row = df_NP[coord]
            if df_SIZ[size] == "m":
                micro.append(row)
            elif df_SIZ[size] == "s":
                small.append(row)
            else:
                medium.append(row)


# groups
local_random = Random(2)
micro_g = local_random.sample(micro, 6)
small_g = local_random.sample(small, 6)
medium_g = local_random.sample(medium, 6)


# normalization of value groups
micro_norm = normalization(micro_g)
small_norm = normalization(small_g)
medium_norm = normalization(medium_g)
y_mic_sum = sum(micro_norm)/len(micro_norm)
y_sma_sum = sum(small_norm)/len(small_norm)
y_med_sum = sum(medium_norm)/len(medium_norm)
y_all_sums = sum((*micro_norm, *small_norm, *medium_norm))


# SSf
T = [y_mic_sum, y_sma_sum, y_med_sum]
Tsq = [i**2 for i in T]
SSf = sum(Tsq)/len(micro_norm)-(y_all_sums**2)/(len(micro_norm)*3)

# SS_all, SSca
SS_all = sum(i**2 for i in [*micro_norm, *small_norm, *medium_norm])\
        -(y_all_sums**2)/6
SSca = SS_all - SSf

# dff, dfca, df_all
dff, df_all = 3-1, 18-1
dfca = df_all - dff

# MSf, MSca
MSf = SSf/dff
MSca = SSca/dfca

# F_obs
F_obs = MSf/MSca
# F_obs = 3.3882100873479146e-34
F_max = 3.59
print(F_obs)
# Учитывая очень маленькое значение (F_obs < F_max) F_obs
# можно полагать, что в зависимости от размера предприятия
# зависит и чистая прибыль.