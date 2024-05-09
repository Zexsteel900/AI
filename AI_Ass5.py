bot_name = "MMCOE Enquiry Desk"

knowledge_base = {

    "what is your name?" : [
        f"My name is {bot_name}! \n Happy to help you out with your College enquiries!"
    ],

    "hello": [
        f"Hello my name is {bot_name}! \n Happy to help you out with your College enquiries!"
    ],

    "what are the Branches in MMCOE ?": [
        "Computer Engineering",
        "Electronics and Telecommunication Engineering",
        "Electrical Engineering",
        "Mechanical Engineering",
        "Artificial Intelligence and Data Science Engineering",
        "Information Technology Engineering"
    ],

    "which are the best branches?" : [
        "Computer Engineering",
        "IT Engineering",
        "Electronics and Telecommunication Engineering"
    ],

    " what is the cut-off for computer engineering?" : [
        "Computer Engineering : 99.8 percentile"
    ],  

    "what is the cut-off for IT Engineering ?" : [
        "IT Engineering : 98.6 percentile"
    ],  

    "what is the cut-off for Entc Engineering?" : [
        "IT Engineering: 97.1 percentile"
    ],    

    "what is the cut-off for Mechanical Engineering?" : [
        "Mechanical Engineering : 92.8 percentile"
    ],  

    "what is the cut-off for Electrical Engineering?" : [
        "Electrical Engineering: 96.2 percentile",
    ],

    "what is the cut-off for AInDS Engineering?" : [
        "AInDS Engineering: 98.8",
    ],
    "When do college admissions start?": [
        "Admissions generally start around August",
    ],
   
}

print("MMCOE Enquiry Rule Based Chatbot")

def respond(user_input):
    if (user_input in knowledge_base):
        print(user_input)
        values = knowledge_base[user_input]
        for value in values:
            print(value)
    else:
        key = user_input
        print("Sorry, Question is not present in the knowledge base! :( \nCould you please enter the appropriate answer for the question below-")
        answer = input("Answer: ")
        knowledge_base[key] = [answer]


while True:
    user_input = input("Enter your query here (or type 'quit' to exit): ").lower()
    if user_input == 'quit':
        print("Thank you for using the Chatbot")
        break
    else:
        respond(user_input)
