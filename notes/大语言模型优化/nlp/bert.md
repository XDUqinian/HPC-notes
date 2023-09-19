# BERT
Pre-training of Deep Bidirectional Transformers for Language Understanding.

BERT 在完形填空任务的启发下，使用带掩码的方式做预训练，并使用不带标号的数据做预训练，使得自然语言任务中也可以向计算机视觉任务一样可以先预训练一个效果比较好的预训练模型，再针对特定任务用带标号的数据做微调。