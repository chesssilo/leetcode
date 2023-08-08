import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    df = employee['salary'].sort_values(ascending=False).drop_duplicates()
    df = pd.DataFrame({'SecondHighestSalary': [None if df.size < 2 else df.iloc[1]]})
    return df