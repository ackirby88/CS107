from __future__ import print_function
import core.AIO as aio

train_data = "/home/akirby/Mass3/Data/MachineLearningData/ImageNet-Sample/train"
train_data = "/home/gridsan/akirby/DataSets/ImageNet/train"
data_pattern = ".JPEG"

# initialize AIO library
aio.init()
print("Hello in py from rank %d" % aio.rank())

# search for training data and partition into local list
local_data = aio.FindData(train_data, data_pattern, search_depth=1, batch_size=32)

# load data files
aio.LoadData(local_data)