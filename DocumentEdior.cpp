#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/*class DocumentEditor{
    private:
    vector<string> documentElements;
    string renderedDocument;

    public:

    void addText(string text)
    {
        documentElements.push_back(text);

    }
    void addImage(string path)
    {
        documentElements.push_back(path);
    }
    string renderDocument(){
        if(renderedDocument.empty()){
        string result;
        
            for(auto ele:documentElements)
            {
                if(ele.size()>4 && ele.substr(ele.size()-4)==".png" || ele.substr(ele.size()-4)==".jpg"){
                    result+="[Image: "+ele+"]"+"\n";               }
                    else{
                        result+=ele+"\n";
                    }
            }
            renderedDocument=result;
        }
        return renderedDocument;
    }

    void saveToFile(){
        ofstream file("document.txt");
        if(file.is_open())
        {
            file<<renderDocument();
            file.close();
            cout<<"Document saved to document.txt"<<endl;
        }
        else
        {
            cout<<"Error: Unable to open file for writing"<<endl;
        }

    }
};
*/

class DocumentElement{
    public:
    virtual string render()=0;
};
class TextElement:public DocumentElement{
    private:
    string text;
    public:
    TextElement(string text){
        this->text=text;
    }
    string render() override{
        return text;
    }
};
int main(){
    DocumentEditor editor;
    editor.addText("Hello World");
    editor.addImage("pic.jpg");
    editor.addText("Document editor welcomes you");

    cout<<editor.renderDocument()<<endl;

    editor.saveToFile();

    return 0;
}