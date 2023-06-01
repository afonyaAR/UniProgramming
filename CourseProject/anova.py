import pandas as pd
from random import sample, Random
from scipy.stats import f_oneway


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
local_random = Random(1)
micro_g = local_random.sample(micro, 6)
small_g = local_random.sample(small, 6)
medium_g = local_random.sample(medium, 6)
print(f_oneway(micro_g, small_g, medium_g))

