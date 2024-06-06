import pandas as pd

def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
  return courses.groupby('class') \
                .count()          \
                .reset_index()    \
                .query('student >= 5')[['class']]