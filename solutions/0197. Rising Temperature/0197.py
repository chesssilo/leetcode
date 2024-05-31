import pandas as pd

def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
  weather['recordDate'] = pd.to_datetime(weather['recordDate'])
  weather['yesterdayDate'] = weather['recordDate'] - pd.Timedelta(days=1)
  df = weather.merge(weather, 
                     left_on='yesterdayDate', 
                     right_on='recordDate', 
                     suffixes=('_today', '_yesterday'))

  return df.query('temperature_today > temperature_yesterday')[['id_today']] \
           .rename(columns={'id_today': 'Id'})