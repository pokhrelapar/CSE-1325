// Apar Pokhrel, 1001646558

#include <iostream>
#include <gtkmm.h>


class MainWindow: public Gtk::Window
{
    public:
        MainWindow();
        void on_OK_Button_click(Gtk::Entry* entry1);
        void on_Cancel_Button_click();


};


void MainWindow::on_OK_Button_click(Gtk::Entry* entry1)
{   

    if(entry1->get_text()=="Natsu Dragneel" || entry1->get_text()=="Natsu")
    {
        Gtk::MessageDialog Right{"You guessed <span fgcolor='#0000ff'>correctly</span>!!", true, Gtk::MESSAGE_WARNING, Gtk::BUTTONS_OK, false};
        Right.set_transient_for(*this);
        int signalR = Right.run();

        if(signalR== Gtk::RESPONSE_OK)
        {
            hide();

        }    

    }

    else
    {
        Gtk::MessageDialog Wrong{"Your answer is not <span fgcolor='#ff0000'>correct.</span>\n Please try again.", true, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, false};
        Wrong.set_transient_for(*this);
        Wrong.run();

    }


}



void MainWindow::on_Cancel_Button_click()
{

    hide();
    
}


MainWindow::MainWindow() 
{
    std::string Name;
    set_default_size(350,350);
    set_title("Welcome to my Guessing Game");
    set_position(Gtk::WIN_POS_CENTER);


    Gtk::Box *MainVBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL,1));
    add(*MainVBox);

    

    Gtk::MenuBar *MyMenuBar = Gtk::manage(new Gtk::MenuBar());
    MainVBox->pack_start(*MyMenuBar, Gtk::PACK_SHRINK, 0);

    Gtk::MenuItem *FirstMenu = Gtk::manage(new Gtk::MenuItem ("Genre Hints", false));
    MyMenuBar->append(*FirstMenu);
    Gtk::Menu *FirstSubMenu = Gtk::manage(new Gtk::Menu());
    FirstMenu->set_submenu(*FirstSubMenu);
    Gtk::MenuItem *SubMenuItem1 = Gtk::manage(new Gtk::MenuItem("Anime",false));
    FirstSubMenu->append(*SubMenuItem1);
    Gtk::MenuItem *SubMenuItem2 = Gtk::manage(new Gtk::MenuItem("Adventure & Wizardy",false));
    FirstSubMenu->append(*SubMenuItem2);




    Gtk::MenuItem *SecondMenu = Gtk::manage(new Gtk::MenuItem ("Names Hints", false));
    MyMenuBar->append(*SecondMenu);
    Gtk::Menu *SecondSubMenu = Gtk::manage(new Gtk::Menu());
    SecondMenu->set_submenu(*SecondSubMenu);
    Gtk::MenuItem *SubMenuItem3 = Gtk::manage(new Gtk::MenuItem("Fairy Tail",false));
    SecondSubMenu->append(*SubMenuItem3);
    Gtk::MenuItem *SubMenuItem4 = Gtk::manage(new Gtk::MenuItem("Dragon Slayer",false));
    SecondSubMenu->append(*SubMenuItem4);
    Gtk::MenuItem *SubMenuItem5 = Gtk::manage(new Gtk::MenuItem("Fire Dragon King",false));
    SecondSubMenu->append(*SubMenuItem5);


    Gtk::MenuItem *ThirdMenu = Gtk::manage(new Gtk::MenuItem ("Friends Hint", false));
    MyMenuBar->append(*ThirdMenu);
    Gtk::Menu *ThirdSubMenu = Gtk::manage(new Gtk::Menu());
    ThirdMenu->set_submenu(*ThirdSubMenu);
    Gtk::MenuItem *SubMenuItem6 = Gtk::manage(new Gtk::MenuItem("Gray",false));
    ThirdSubMenu->append(*SubMenuItem6);
    Gtk::MenuItem *SubMenuItem7 = Gtk::manage(new Gtk::MenuItem("Erza",false));
    ThirdSubMenu->append(*SubMenuItem7);
    Gtk::MenuItem *SubMenuItem8 = Gtk::manage(new Gtk::MenuItem("Happy",false));
    ThirdSubMenu->append(*SubMenuItem8);

    Gtk::MenuItem *FourthMenu = Gtk::manage(new Gtk::MenuItem ("Magic & Abilities", false));
    MyMenuBar->append(*FourthMenu);
    Gtk::Menu *FourthSubMenu = Gtk::manage(new Gtk::Menu());
    FourthMenu->set_submenu(*FourthSubMenu);
    Gtk::MenuItem *SubMenuItem9 = Gtk::manage(new Gtk::MenuItem("Fire Dragon's Roar",false));
    FourthSubMenu->append(*SubMenuItem9);
    Gtk::MenuItem *SubMenuItem10 = Gtk::manage(new Gtk::MenuItem("Crimson Lotus: Phoenix Blade",false));
    FourthSubMenu->append(*SubMenuItem10);
    Gtk::MenuItem *SubMenuItem11 = Gtk::manage(new Gtk::MenuItem("Fire Dragon King's Purgatory",false));
    FourthSubMenu->append(*SubMenuItem11);


    


    Gtk::Label *MyLabel = Gtk::manage(new Gtk::Label("\n\n What is this character's name?\n\n"));
    MainVBox->add(*MyLabel);
    MyLabel->set_justify(Gtk::JUSTIFY_CENTER);

    Gtk::Image *MyImage = Gtk::manage(new Gtk::Image{"Natsu.jpg"});
    MainVBox->add(*MyImage);

  

    Gtk::Box *hBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL,0));
    MainVBox->add(*hBox);



    Gtk::Button  *ButtonOK = Gtk::manage(new Gtk::Button("OK"));
    hBox->add(*ButtonOK);
    ButtonOK->set_size_request(350);
   

    Gtk::Entry *entry1 = Gtk::manage(new Gtk::Entry());
    entry1->set_text("Enter your guess here");
    hBox->add(*entry1);
    entry1->grab_focus(); 
    entry1->set_width_chars(50);

    ButtonOK->signal_clicked().connect(sigc::bind<Gtk::Entry*>(sigc::mem_fun(*this, &MainWindow::on_OK_Button_click), entry1));
    entry1->signal_activate().connect(sigc::bind<Gtk::Entry*>(sigc::mem_fun(*this, &MainWindow::on_OK_Button_click),entry1));
  

    Gtk::Box *hBox1 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL,0));
    MainVBox->add(*hBox1);


    Gtk::Button  *ButtonCancel = Gtk::manage(new Gtk::Button("Cancel"));
    hBox1->add(*ButtonCancel);
    ButtonCancel->set_size_request(350);
    ButtonCancel->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_Cancel_Button_click));

    

  //  Gtk::MessageDialog *Right = Gtk::manage(new Gtk::MessageDialog{"You guessed <span fgcolor='#0000ff'>correctly</span>!!", true, Gtk::MESSAGE_WARNING, Gtk::BUTTONS_OK, false});
   // Gtk::MessageDialog *Wrong = Gtk::manage(new Gtk::MessageDialog{"Your answer is not <span fgcolor='#ff0000'>correct.</span>\n"+"Please try again.", true, Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, false});



    MainVBox->show_all();


}



int main(int argc , char *argv [])
{
    auto app = Gtk::Application::create(argc, argv, "");

    MainWindow MyWindow;

    return app->run(MyWindow);

     
}



