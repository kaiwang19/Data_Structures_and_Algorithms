## WMK

This is the project from group 6 in KDD-20 of HKUST.  

Group members :
  * DING, Weizhen (12229218)  
  * MOTI, Moin Hussain (20538314)  
  * WANG, Kai (20738081)  

Group topic : **Classification of hyper-spectral images using advanced feature extraction methods**.  

## References

  * SVM (baseline)
  * Hu - Deep Convolutional Neural Networks for Hyperspectral Image Classification, Hu et al., Journal of Sensors 2015. [Paper](http://downloads.hindawi.com/journals/js/2015/258619.pdf)
  * Lee - Contextual Deep CNN Based Hyperspectral Classification, Lee and Kwon, IGARSS 2016. [Paper](https://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=7729859)
  * Li - Spectral–Spatial Classification of Hyperspectral Imagery with 3D Convolutional Neural Network, Li et al., Remote Sensing 2017. [Paper](https://www.mdpi.com/2072-4292/9/1/67/htm)
  * Mou - Deep recurrent neural networks for hyperspectral image classification. Lichao Mou, Pedram Ghamisi, Xiao Xang Zhu. TGRS 2017. [Paper](https://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=7914752)
  * Hamida - 3-D Deep Learning Approach for Remote Sensing Image Classification, Hamida et al., TGRS 2018. [Paper](https://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=8344565)
  * He - Multi-scale 3D Deep Convolutional Neural Network for Hyperspectral Image Classification, He et al, ICIP 2017. [Paper](https://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=8297014)
  * HybirdSN - HybridSN: Exploring 3D-2D CNN Feature Hierarchy for Hyperspectral Image Classification, Swalpa Kumar Roy, Gopal Krishna, Shiv Ram Dubey, Bidyut B. Chaudhuri.,  IGARSS 2020. [Paper](https://arxiv.org/pdf/1902.06701.pdf)



## Datasets

We use popular [public dataset](http://www.ehu.eus/ccwintco/index.php/Hyperspectral_Remote_Sensing_Scenes):
  * Indian Pines
  * Salinas
  * Pavia Center
  * Pavia University
  * Kennedy Space Center


## Requirements

  * [Visdom](https://github.com/facebookresearch/visdom)
  * [PyTorch](http://pytorch.org/)
  * Python 2.7 / Python 3.5+  
  
  
## Usage

  * Input datasets from {IndianPines, PaviaC, PaviaU, KSC, Salinas}, then the script will run all the models in this dataset.
```
cd scripts/ ./batch_dataset.sh IndianPines 
```

  * Input models from {SVM, Hu, Lee, Li, Mou, Hamida, He}, then the script will run all the model in all the datasets.
```
cd scripts/ ./batch_model.sh SVM
```
Check the res/ directory for files restoring results.

  * To run HybirdSN model, please use Jupyter notebook.

## Results
  * Indian Pines
![Indian Pines Accuracy](Figures/Acc1.png)

  * Salinas
![Salinas Accuracy](Figures/Acc2.png)

  * Pavia Center
![Pavia Center Accuracy](Figures/Acc3.png)

  * Pavia University
![Pavia University Accuracy](Figures/Acc4.png)

  * KSC
![KSC Accuracy](Figures/Acc5.png)

  * Time Elapsed
![Time Elapsed](Figures/Time.png)
