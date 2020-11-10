#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDomDocument>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"Xml";
  //  changexmlvalue(1,"name","chunxiao");
    //    getxmlkey(1,"price");
    writexml();

   // QVariant getxmlkey(KeyType ntype);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readxml()
{

    //打开文件
        QFile file("C:/Users/Administrator/Desktop/food.xml");
        if(!file.open(QFile::ReadOnly))
        {
            return;
        }

    //DOM关联文件操作
        QDomDocument doc;
        if(!doc.setContent(&file))
        {
            file.close();
            return;
        }
        file.close();
    //输出根节点
        QDomElement root=doc.documentElement();
        qDebug()<<root.nodeName();

        //获取第一个节点
        QDomNode node=root.previousSibling();

        node=root.firstChild();
         //读
        while (!node.isNull())
        {
             QDomElement element=node.toElement();
              qDebug()<<element.tagName();
             QDomNodeList list=element.childNodes();
             for(int i=0;i<list.count();++i)
             {
                 QDomNode n=list.at(i);
                 qDebug()<<n.nodeName()<<":"<<n.toElement().text();
             }
                qDebug()<<"/"+element.tagName();
              //下一个兄弟节点
             node=node.nextSibling();
       }
}


void MainWindow::changexmlvalue(int nd,const QString &key,const QString &value)
{

    //打开文件
        QFile file("C:/Users/Administrator/Desktop/food.xml");
        if(!file.open(QFile::ReadOnly))
        {
            return;
        }

       //DOM关联文件操作
        QDomDocument doc;
        if(!doc.setContent(&file))
        {
            file.close();
            return;
        }
        file.close();
       //输出根节点
        QDomElement root=doc.documentElement();
        qDebug()<<root.nodeName();
        //获取第一个节点
         QDomNode node=root.previousSibling();

         node=root.firstChild();
         //读

         int j=1;
         while (!node.isNull())
         {

                     QDomElement element=node.toElement();
                 //修改节点
                 //遍历第一个节点的子节点
                     QDomNodeList list1=element.childNodes();
                     for(int i=0;i<list1.count();++i)
                      {
                          QDomNode n=list1.at(i);
                          QString tagName = n.toElement().tagName(); //获取节点的元素名称

                          if ((tagName.compare(key) == 0) && (nd==j))        //节点标记查找,名称为"name"的节点
                          {
                                QDomNode oldNode = n.firstChild();
                                n.firstChild().setNodeValue(value);
                                //新建一个新的newNode子节点
                                QDomNode newNode = n.firstChild();
                                //使用replaceChild替换node
                                n.replaceChild(newNode,oldNode);
                          }
                        qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                      }
                  //下一个兄弟节点
                 node=node.nextSibling();
                 j++;
      }
}

void MainWindow::file()
{

}

void MainWindow::getxmlkey(int nd,const QString &key) //QVariant getxmlkey(KeyType ntype);
{
    //1.取出枚举当中的值
    //2.实参和枚举值相比,类型匹配，
    //3.读xml配置文件的key值对应的value值 ，将value值 封进QVariant返回

//SplitServerIp

//    for()
//    {
//        if(enum[]== "SplitServerIp")
//    }

    //打开文件
        QFile file("C:/Users/Administrator/Desktop/food.xml");
        if(!file.open(QFile::ReadOnly))
        {
            return;
        }

       //DOM关联文件操作
        QDomDocument doc;
        if(!doc.setContent(&file))
        {
            file.close();
            return;
        }
        file.close();
       //输出根节点
        QDomElement root=doc.documentElement();
        qDebug()<<root.nodeName();
        //获取第一个节点
         QDomNode node=root.previousSibling();

         node=root.firstChild();
         //读

         int j=1;
         while (!node.isNull())
         {

                     QDomElement element=node.toElement();
                 //修改节点
                 //遍历第一个节点的子节点
                     QDomNodeList list1=element.childNodes();
                     for(int i=0;i<list1.count();++i)
                      {
                          QDomNode n=list1.at(i);
                          QString tagName = n.toElement().tagName(); //获取节点的元素名称

                          if ((tagName.compare(key) == 0)&& (nd==j))        //节点标记查找,名称为"name"的节点
                          {
                               qDebug()<<"key值已找到:"<<n.nodeName();
                           }

                       // qDebug()<<n.nodeName()<<":"<<n.toElement().text();
                      }
                  //下一个兄弟节点
                 node=node.nextSibling();
                 j++;
      }
}


void  MainWindow::writexml()
{
    //打开或创建文件
    //if("filename2"==filename)
    //{}

        QString fileName("C:/Users/Administrator/Desktop/test.xml");
        QFile file(fileName);
        //QIODevice::Truncate表示清空原来的内容
        if(!file.open(QFile::WriteOnly | QFile::Truncate))
            return;

        //创建xml文档在内存中
        QDomDocument doc;

        QDomProcessingInstruction instruction;//添加处理命令
        instruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
        //创建注释
        doc.appendChild(instruction);

        //添加根节点
        QDomElement root=doc.createElement("library");
       // root.setAttribute("Version","2.1");
        doc.appendChild(root);
        //添加第一个子节点及其子元素
        QDomElement book=doc.createElement("book");
        //方式一：创建属性  其中键值对的值可以是各种类型
        QDomAttr id=doc.createAttribute("id");
        id.setValue("1");
        book.setAttributeNode(id);
      //  book.setAttribute("id",1);
      //  book.setAttribute("time","2013/6/13");
        //方式二：创建属性 值必须是字符串
        QDomAttr time=doc.createAttribute("time");
        time.setValue("2013/6/13");
        book.setAttributeNode(time);


        QDomElement title=doc.createElement("title"); //创建子元素
        QDomText text; //设置括号标签中间的值
        text=doc.createTextNode("C++ primer");
        book.appendChild(title);
        title.appendChild(text);
        QDomElement author=doc.createElement("author"); //创建子元素
        text=doc.createTextNode("Stanley Lippman");
        author.appendChild(text);
        book.appendChild(author);
        //添加节点book做为根节点的子节点
        root.appendChild(book);

        //添加第二个子节点及其子元素
        book=doc.createElement("book");
        book.setAttribute("id",2);
        time=doc.createAttribute("time");
        time.setValue("2007/5/25");
        book.setAttributeNode(time);
        title=doc.createElement("title");
        text=doc.createTextNode("Thinking in Java");
        book.appendChild(title);
        title.appendChild(text);

        author=doc.createElement("author");
        text=doc.createTextNode("Bruce Eckel");
        author.appendChild(text);
        book.appendChild(author);
        root.appendChild(book);

        //输出到文件
        QTextStream out_stream(&file);
        doc.save(out_stream,4); //缩进4格
        file.close();
}















/*
 * 同一个问题不同的搜法，就有不同的结果

    1.XML文件/Qt的xml文件模块介绍，XML类，方法，注释等.
            14:29	~14:45
            Qt解析XML的3种方式

    2.先先找一个xml文件,放在本地目录下.   ok

    3.读文件:xml文件的读取
                1.找一篇合适的文章,看懂后，自己写  15:20: ~15:40
                        看懂别人的代码后，划分成块，列举出来都那几块，依次完成

    4.修改xml配置文件key对应的value值

    5.获取xml文件读取对应key的值

    6.根据读的内容写一个xml文件
*/
/*
    1.看别人代码
    2.划分成块
    3.看用到的类，用到的方法
    4.自己动手写/写伪码



*/
