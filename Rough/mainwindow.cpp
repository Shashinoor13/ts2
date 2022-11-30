#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"profile.h"
#include<QMessageBox>
#include"contactus.h"
#include<namobuddha.h>
#include<hazarsidi.h>
#include<chandragiri.h>
#include<pokhara.h>
#include"booknow.h"


//QString chandragiri = "Chandragiri Hills is one of the popular sites in Nepal to visit with your families and friends."
//                      " It has grabbed the attention of several travelers all over the world due to its unmatched beauty. On the lap of Chandragiri Hill resides a sacred temple of Lord Shiva at an altitude of 2551 meters. Chandragiri Hill is also one of the popular hill stations near the Kathmandu valley, where you can enjoy the snowfall during winter."
//                      " Besides snowfall, several features of Chandragiri will enhance your traveling experience, such as the sacred temple of Bhaleshwor Mahadev Temple." ;


//QString NamoBuddha = "Namobudha is one of the most important religious sites of the Buddhists after Kathmandu's, Swyambhunath and Bouddhanath."
//                     " It is located on a picturesque hill, 45 km along Banepa, Panauti route. "
//                     "The religiously important Namobuddha, surrounded by serene environment and green hills, is gaining fame as an important Buddhist pilgrimage site" ;

//QString Pokhara = "Pokhara ticks all the right boxes, with spectacular scenery, adventure activities, and accommodation and food choices galore."
//                 " Whether you’ve returned from a three-week trek or endured a bus trip from hell, Lakeside Pokhara is the perfect place to recharge your batteries."

//                  "The tranquil lakes and the earthy ambiance of Pokhara takes us close to nature. You can spend your vacation at the lakeside in the daytime and then enjoy the nightlife of Pokhara."
//                    "You can visit the caves and crawl out of them. It will be an exciting experience. Similarly, you can try some adventurous sports and challenge yourself."
//                    "Other than that, you can go on a short excursion to some beautiful places in Pokhara and make memorable moments. Don’t forget to try some unique and delicious foods of Pokhara and explore the life of people here." ;

//QString ThousandStep = "Dhulikhel Hajar Sidi, one of Dhulikhel’s star attractions, is a picnic spot, or a refreshment zone. Hajar Sidi, meaning thousand-steps, is the name of the place because you reach the top of the area by climbing a thousand concrete steps. A naturally standing massive stone rests on the top, a popular spot for people to take photos."
//                         " You can find reasonable accommodations, with beautiful window views, and amazing Nepali cuisines. A perfect place for a day out with friends or families, via hike or bikes, you can feel escaped from the busy streets of Kathmandu and connected to nature." ;

 extern QSqlDatabase db;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_NamoBuddha_PushButton_clicked()
{
     Namobuddha namobuddha;
     namobuddha.setModal(true);
     namobuddha.exec();
}


void MainWindow::on_Pokhara_PushButton_clicked()
{
    class Pokhara pokhara;
    pokhara.setModal(true);
    pokhara.exec();
}


void MainWindow::on_ThousandStep_PushButton_clicked()
{
    class hazarsidi thousand_step;
    thousand_step.setModal(true);
    thousand_step.exec();
}


void MainWindow::on_Chandragiri_PushButton_clicked()
{
   class chandragiri chandragiri;
    chandragiri.setModal(true);
    chandragiri.exec();
}








void MainWindow::on_bookNow_clicked()
{
    BookNow bn ;
    hide() ;
    bn.exec() ;
}


void MainWindow::on_Profile_clicked()
{
    class profile p;
    hide();
    p.exec();
}




void MainWindow::on_ContactUs_clicked()
{
    ContactUs developersInfo ;
    developersInfo.setModal(true);
    developersInfo.exec() ;
}

