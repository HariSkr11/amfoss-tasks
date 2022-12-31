import requests
import os
key = os.getenv("api")
def get_movie_info(message,key = os.getenv("api")):
    url = f"http://www.omdbapi.com/?apikey={key}&t={message}"
    re = requests.get(url)
    if re.status_code == 200:
        json_dict= re.json()
        if 'Error' in json_dict.keys():
            flag = False
            return flag,"Movie not found!, Please try again",None,None
        else:
            flag = True
            name = f"Movie name:{json_dict['Title']}\n"
            year = f"Year:{json_dict['Year']}\n"
            release_date = f"Released:{json_dict['Released']}\n"
            rating = f"imdbRating:{json_dict['imdbRating']}\n"
            poster = json_dict['Poster']
            out_str = name+year+release_date+rating
            return flag,out_str,poster,parameters(json_dict)
    else:
        return "Sorry the OMDB page was not found or there is some server issue or API issue"
def parameters(json_dict):
    return {'Title':json_dict['Title'],
            'Year':json_dict['Year'],
            'Released':json_dict['Released'],
            'imdbRating':json_dict['imdbRating']}
