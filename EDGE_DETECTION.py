#!/usr/bin/env python
# coding: utf-8

# In[1]:


# sobel.py
import cv2
import numpy as np
import math
import matplotlib.pyplot as plt


# In[2]:


img = cv2.imread('objects.png')
img[:, :, 0], img[:, :, 2] = img[:, :, 2], img[:, :, 0].copy()
plt.imshow(img)


# In[3]:


img = cv2.imread('objects.png', cv2.IMREAD_GRAYSCALE)
img = np.array(img)
rows, cols = img.shape
plt.imshow(img, cmap='gray')


# In[4]:


# Function to save new image


def save_gray(img, file_name):
    z = img.copy()
    cv2.imwrite(file_name + ".png", z, [0])


# In[5]:


Gx = [[-1, 0, 1],
      [-2, 0, 2],
      [-1, 0, 1]]
Gy = [[-1, -2, -1],
      [0, 0, 0],
      [1, 2, 1]]
Gx = np.array(Gx)
Gy = np.array(Gy)


# In[6]:


shape = img.shape
rows = shape[0]
columns = shape[1]
mag = np.zeros((img.shape))
magx = np.zeros((img.shape))
magy = np.zeros((img.shape))
angle = np.zeros((img.shape))


# In[7]:


for i in range(1, rows-1):
    for j in range(1, columns - 1):
        slice = img[i-1:i+2, j-1:j+2]
        S1 = sum(sum(slice * Gx))
        S2 = sum(sum(slice * Gy))

        magx[i+1][j+1] = S1
        magy[i+1][j+1] = S2
        if S1 != 0:
            angle[i+1][j+1] = S2/S1
        mag[i+1][j+1] = max(70, math.sqrt(S1**2+S2**2))
        if S2 != 0 or angle[i+1][j+1] != 0:
            mag[i+1][j+1] = mag[i+1][j+1] * (angle[i+1][j+1] * (S1/S2))


# In[8]:


save_gray(magx, 'sobelx')
save_gray(magy, 'sobely')
save_gray(mag, 'sobel')


# In[9]:


magx = cv2.imread('sobelx.png', cv2.IMREAD_GRAYSCALE)
plt.imshow(magx, cmap='gray')


# In[10]:


magy = cv2.imread('sobely.png', cv2.IMREAD_GRAYSCALE)
plt.imshow(magy, cmap='gray')


# In[11]:


mag = cv2.imread('sobel.png', cv2.IMREAD_GRAYSCALE)
plt.imshow(mag, cmap='gray')


# In[12]:


X = int(input("Enter the coordinate X at which angle is required: "))
Y = int(input("Enter the coordinate Y at which angle is required: "))
print(angle[X][Y])

