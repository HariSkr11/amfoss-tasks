import csv
import os.path
def dump_csv(parameter):
    a = os.path.exists('movie.csv')
    if (not(a)):
        with open("movie.csv",'w',newline='') as file:
            columns = ['Title','Year','Released','imdbRating']
            dic = csv.DictWriter(file, fieldnames=columns)
            dic.writerow({'Title':'Title',
                'Year':'Year',
                'imdbRating':'imdbRating',
                'Released':'Released'})
            dic.writerow(parameter)
    else:
        with open("movie.csv",'a',newline='') as file:
            columns = ['Title','Year','Released','imdbRating']
            dic = csv.DictWriter(file, fieldnames=columns)
            dic.writerow(parameter)

