import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, n: int) -> pd.DataFrame:
    df = employee['salary'].drop_duplicates()
    df = df.sort_values(ascending=False)

    if n > len(df):
        return pd.DataFrame({'Nth Highest Salary': [None]})

    df = df.iloc[n - 1]

    return pd.DataFrame({'Nth Highest Salary': [df]}) 