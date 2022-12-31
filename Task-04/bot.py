import scrapping
import telebot
import dumping
import os
bot  = telebot.TeleBot(os.getenv("telebot"))
@bot.message_handler(commands=['start', 'hello'])
def greet(message):
    global botRunning
    botRunning = True
    bot.reply_to(
        message, 'Hello there! I am a bot that will show movie information for you and export it in a CSV file.\n\n')


@bot.message_handler(commands=['stop', 'bye'])
def goodbye(message):
    global botRunning
    botRunning = False
    bot.reply_to(message, 'Bye!\nHave a good time')
    try:
        os.remove("movie.csv")
    except:
        a=1

@bot.message_handler(func=lambda message: botRunning, commands=['help'])
def helpProvider(message):
    bot.reply_to(message,'1.0 You can use \"/movie MOVIE_NAME\" command to get the details of a particular movie. For eg: \"/movie The Shawshank Redemption\"\n\n2.0. You can use \"/export\" command to export all the movie data in CSV format.\n\n3.0. You can use \"/stop\" or the command \"/bye\" to stop the bot.')


@bot.message_handler(func=lambda message: botRunning, commands=['movie'])
def reply_movie_info(message):
    bot.reply_to(message,"Getting movie info...")
    movie_name = message.text.split("/movie ")[1]
    flag,out_str,poster,csv_info = scrapping.get_movie_info(movie_name)
    if flag:
        bot.send_message(message.chat.id,"Movie found!")
        chid = message.chat.id
        bot.send_photo(chid,poster,out_str)
        dumping.dump_csv(csv_info)
    else:
        bot.send_message(message.chat.id,out_str)

@bot.message_handler(func=lambda message: botRunning, commands=['export'])
def getList(message):
    bot.reply_to(message, 'Generating file...')
    #TODO: 2.2 Send downlodable CSV file to telegram chat
    try:
        with open("movie.csv",'rb') as file:
            bot.reply_to(message,"File generated!")
            bot.send_document(message.chat.id,file)
    except:
        bot.send_message(message.chat.id,"Uh Oh It looks like you have not searched for a movie until now!")


@bot.message_handler(func=lambda message: botRunning)
def default(message):
    bot.reply_to(message, 'I did not understand '+'\N{confused face}')

bot.infinity_polling()
