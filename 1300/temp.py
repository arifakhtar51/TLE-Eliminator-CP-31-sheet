def count_words(input_string):
    # Split the string into words based on whitespace
    words = input_string.split()
    # Return the number of words
    return len(words)

# Example usage
user_input = """ extraordinary situations demand extraordinary interventions
 The above phrase connotes for stringent measures to be taken for sustainable development in 
order to attain a sustainable future. This is more challenging for the most populated 
developing Nation i.e. India. However, the existing efforts of the government in the areas of 
sustainable development such as National Solar Mission , UJALA etc. coupled with new ideas 
and innovations will drive India towards an untapped opportunity for a sustainable future.
 India has robust potential for expanding its renewable resource.To increase the Solar Energy 
capacity, the government should expand the policies (such as National Solar 
Mission,Panchamrit) through public-private partnership ,more technological apparatus should be 
installed in the regions of Rajasthan and Gujarat to efficiently harness wind energy. Government 
should also promote biomass energy by providing incentives to bio-plants. There is a need to 
promote electric vehicles through tax incentives for promoting renewable energy.
 Apart from renewable energy, sustainable agriculture plays a conspicuous role in ensuring 
good health and well-being of an individual thus enhancing the productivity of the economy. 
Todays agriculture which is plagued by various chemical fertilizers and pesticides needs to be 
halted. Measures such as- Awareness for sustainable farming should be given to farmers, more 
subsidies should be given to those farmers opting for organic farming,agroforestry and 
Permaculture initiatives should be expanded based on community based engagement.
 Today the waste treatment problem became a grave obstacle generating large amounts of 
waste everyday which remain untreated. Thus, halting the Smart City mission.
 For effectively reducing waste following measures should be opted- segregation of waste in 6 
different dustbins [green dustbin for Organic waste, blue dustbin for recyclable waste such as 
paper, plastic bottles, cans etc.red dustbin for electronic gadgets ,yellow dustbin for non 
recyclable waste such as plastic bags, brown dustbin for sanitary waste and black dustbin for 
rejected waste such as broken glass] . Training should be given to waste collectors on how to 
segregate waste on household level and garbage trucks should also be designed in the same 
way.Municipal corporation should take measures to implement it on ground level by engaging 
communities and different groups such as various NGOs. Social media and newspapers should 
participate robustly to create mass awareness. System of hierarchical felicitation should be 
organized on household level as well as to different wards, creating a healthy competition and 
sense of community involvement. The above measures if executed by the administrative bodies 
with full potential will guide India towards a more sustainable future. Besides this, there is a 
need for more investment in waste to energy technologies , for instance, Pyrolysis and 
Gasification for those plastics which are non-recyclable. We need to inculcate smart 
technologies in waste management with IOT-enabled bins and mobile apps to record illegal 
dumpings.
Today, global warming is the most severe challenge that the world is facing. The internationally 
agreed goal to keep the world's temperature rise below 1.5°c ,calls for an urgent need to 
incorporate green infrastructure.
 It promotes a sustainable environment by improving the air quality, reducing the impacts of 
global warming and also promoting the well-being of people. For enhancing the green 
infrastructure project, following initiatives should be taken-  increasing afforestation(one such 
initiative was ek ped maa ke naam), engaging people through unique ways such as, House tax 
incentives given to those people who have planted trees in their homes or have terrace 
gardening . A green card sticker should be pasted(as a method of felicitation)by the district 
authorities on the doors of those houses who have incorporated these initiatives. This will lead 
to healthy competition in the society. Ideas such as Zero Carbon Buildings Action 
Plan(ZCBAP) , as recently
 opted by Nagpur city, should be popularized.
              We need to take examples from Denmark who adopted carbon capture and storage 
technology which collects carbon dioxide from surrounding regions and compresses it into liquid 
then stores it underground. This helps the country in achieving the target of 'zero carbon 
emission' by 2050.
 Permeable pavement through which water can percolate, green walls, rain gardens and efficient 
management of rainwater runoff should be prioritize.Also water-tank bells should be installed in 
every household to stop wastage of water. We need to create awareness to reduce carbon 
emissions by promoting Bicycle-friendly infrastructure.
 With 66% of its population below the age of 35, India stands as the world's largest youth 
population having significant potentials to lead India's destination towards a sustainable future. 
Government bodies can occupy a nodal position to integrate India's youth and business for 
sustainable development.Government should popularise initiatives such as creating mass 
awareness in youth regarding the necessity of sustainable development. It will be a good 
initiative to create environment leaders in every college and school unit and the best 
performing leaders of districts should be felicitated by the chief minister of the following states. 
Different platforms(for instance, viksit  Bharat, National Youth Parliament etc.)should be 
organised to welcome ideas of young leaders.Besides, the government can generate green 
jobs in the areas of renewable energy, sustainable agriculture, green infrastructure and various 
eco-tourism programs. Grants and loans should be given to young entrepreneurs who are 
seeking sustainable business. Private Ventures can play a conspicuous role in engaging more 
youth in internship programs in the areas of sustainable development.
                We do not inherit the Earth from our ancestors, we borrow it from our children  
                                              By Mahatma Gandhi.
 The above quote of Gandhi ji, reminds us of the duty of every citizen to protect the environment 
for future generations . Thus, pointing to the immense need to promote sustainable 
development"""
word_count = count_words(user_input)
print(f"The number of words in the string is: {word_count}")
