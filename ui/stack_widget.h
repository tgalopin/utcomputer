#ifndef LO21_UI_STACK_H
#define LO21_UI_STACK_H


#include <gtkmm.h>
#include "../lib/repository/observable.h"
#include "../lib/literal/stack.h"
#include "../lib/literal/interface.h"

class StackWidget: public RepositoryObserver, public Gtk::TreeView {
protected:
    class ModelColumns: public Gtk::TreeModel::ColumnRecord {
    public:
        ModelColumns() {
            add(col_id);
            add(col_value);
        }

        Gtk::TreeModelColumn<int> col_id;
        Gtk::TreeModelColumn<Glib::ustring> col_value;
    };

    ModelColumns columns;
    Glib::RefPtr<Gtk::Builder> builder;
    Glib::RefPtr<Gtk::ListStore> refTreeModel;
    unsigned int nbAff;

public:
    StackWidget(BaseObjectType *treeview, const Glib::RefPtr<Gtk::Builder> &builder);

    void setNb(unsigned int nbAff) {
        this->nbAff = nbAff;
    }

    virtual void update(Repository *repository);
};

#endif // LO21_UI_STACK_H
