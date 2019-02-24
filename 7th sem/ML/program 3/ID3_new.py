import pandas as pd
import numpy as np
#Import the dataset and define the feature as well as the target datasets / columns#
dataset = pd.read_csv('playtennis.csv',
                      names=['outlook','temperature','humidity','wind','class',])

attributes =('Outlook','Temperature','Humidity','Wind','PlayTennis')

def entropy(target_col):
    elements,counts = np.unique(target_col,return_counts = True)
    entropy = np.sum([(-counts[i]/np.sum(counts))*np.log2(counts[i]/np.sum(counts)) for i in range(len(elements))])
    return entropy

def InfoGain(data,split_attribute_name,target_name="class"):
    total_entropy = entropy(data[target_name])
    vals,counts= np.unique(data[split_attribute_name],return_counts=True)
    Weighted_Entropy = np.sum([(counts[i]/np.sum(counts))*entropy(data.where(data[split_attribute_name]==vals[i]).dropna()[target_name]) for i in range(len(vals))])
    Information_Gain = total_entropy - Weighted_Entropy
    return Information_Gain
       

def ID3(data,originaldata,features,target_attribute_name="class",parent_node_class = None):    
#Define the stopping criteria --> If one of this is satisfied, we want to return a leaf node#
    if len(np.unique(data[target_attribute_name])) <= 1:
        return np.unique(data[target_attribute_name])[0]
    
    elif len(features) ==0:
        return parent_node_class
       
    else:
       
        unique_TA=np.unique(data[target_attribute_name],return_counts=True)[1]
        max_unique_TA=np.argmax(unique_TA)
        parent_node_class=np.unique(data[target_attribute_name])[max_unique_TA]
           
        item_values = [InfoGain(data,feature,target_attribute_name) for feature in features] 
        best_feature_index = np.argmax(item_values)
        best_feature = features[best_feature_index]
        
        tree = {best_feature:{}}
                
        features = [i for i in features if i != best_feature]
                    
        for value in np.unique(data[best_feature]):
            value = value
            sub_data = data.where(data[best_feature] == value).dropna()
            subtree = ID3(sub_data,dataset,features,target_attribute_name,parent_node_class)
            tree[best_feature][value] = subtree
        return(tree)    
                    
def predict(query,tree,default = 1):
    for key in list(query.keys()):
        if key in list(tree.keys()):
            result = tree[key][query[key]] 
    if isinstance(result,dict):
        return predict(query,result)
    else:
        return result
               
def train_test_split(dataset):
    training_data = dataset.iloc[:14].reset_index(drop=True)
    return training_data  #,testing_data

def test(data,tree):
    queries = data.iloc[:,:-1].to_dict(orient = "records")
    #Create a empty DataFrame in whose columns the prediction of the tree are stored
    predicted = pd.DataFrame(columns=["predicted"]) 
    #Calculate the prediction accuracy
    for i in range(len(data)):
        predicted.loc[i,"predicted"] = predict(queries[i],tree,1.0) 
        
    print('The prediction accuracy is: ',(np.sum(predicted["predicted"] == data["class"])/len(data))*100,'%')
    
"""
Train the tree, Print the tree and predict the accuracy
"""
XX = train_test_split(dataset)
training_data=XX
tree = ID3(training_data,training_data,training_data.columns[:-1])
print(' Display Tree',tree)
print('len=',len(training_data))
test_data = dataset.iloc[14:17].reset_index(drop=True)
test(test_data,tree)