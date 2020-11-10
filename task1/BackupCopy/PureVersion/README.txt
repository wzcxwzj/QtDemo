api:

	void writeXml();
	描述:
		在当前目录下写XML文件

    	void changeXmlValue(KeyType ntype,const QVariant &value);
	描述:
		读XML文件,改变value值,并重写XML文件

    	QVariant getXmlValue(KeyType ntype);
	描述:
		读XML文件,获取Value值