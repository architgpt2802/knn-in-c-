# **KNN ALGORITHM IMPLEMENTATION IN C++**

**K Nearest Neighbours** is a machine learning algorithm that stores all the available cases and classifies the new data or case based on the similarity measure. It suggests that if you are similar to your neighbour then you are one of them.

Ex: if mango looks more similar to apple, orange, banana than it is to monkey, elephant, dog; then most likely mango belongs to the group of fruits.

KNN can be used for both classification and regression predictive problems. However, it is most widely used in the classification prediction problems.

## HOW DOES KNN WORK

Let’s take a simple case to understand this algorithm. Following is the spread of red circles and green squares:

![](https://github.com/architgpt2802/knn-in-cpp/blob/master/readme%20images/r_img_1.png)

Now we intend to find out the class of the blue star. The blue star can be either red circle or green square. K is the number of nearest neighbours we are considering. Let us take K = 3. Now we consider three points closest to the blue star.

![](https://github.com/architgpt2802/knn-in-cpp/blob/master/readme%20images/r_img_2.png)

## KNN in C++:

Machine learning is mostly implemented using Python and R languages. There are a lot of libraries and modules available. Scikit-learn by Google is the most popularly used library in machine learning. With the help of these libraries, algorithms such as KNN can be implemented fairly easily by just using a simple function.

But C++ is not a language anyone would consider for machine learning. Nor are there many modules available for the purpose.

So, I implemented KNN in C++ without using any machine learning libraries. Here, I will predict the classification of a point in a graph between the two categories.

There are two classes of points, RED and ORANGE. Also I have a BLUE point which I aim to make the machine predict and classify it between RED and ORANGE.

_Actually, the point should be classified as **RED**._

![](https://github.com/architgpt2802/knn-in-cpp/blob/master/readme%20images/r_table.png)

![](https://github.com/architgpt2802/knn-in-cpp/blob/master/readme%20images/r_graph.png)

## ALGORITHM:

    1) Import the data in array. Two arrays to store X and Y values differently.
In another array, store the corresponding class of the points. Here, 0 is for orange and 1 is for red.
    2) Initialise the value of K. I’m taking K as 5. Hence, we will consider 5 nearest neighbours.
    3) Calculate the distance of each and every point from the blue point and store in an array.
I’m using Euclidean distance for calculating the distance between the points.
    4) Now sort the array in ascending order and take first K number of points.
    5) Count the number of red and orange points in those K points.
    6) The point will belong to the category which appears more in those K points.


Here is a screen snap of the output.

![](https://github.com/architgpt2802/knn-in-cpp/blob/master/output_1.png)

It classified it as **RED** correctly.

I have put another output for the blue point to be (1, 2) and K=7.

![](https://github.com/architgpt2802/knn-in-cpp/blob/master/output_2.png)

And yes, It predicted right again!


## REFFERENCES:

1) [GeeksforGeeks](https://www.geeksforgeeks.org/)
2) [stackoverflow](https://stackoverflow.com/)
3) [Analytics Vidhya](https://www.analyticsvidhya.com/blog/2018/03/introduction-k-neighbours-algorithm-clustering/)
4) [scikit learn](https://scikit-learn.org/)

## CREATED BY:

**ARCHIT GUPTA**

E-Mail: architgpt2802@gmail.com

[_architgpt2802_](https://github.com/architgpt2802)