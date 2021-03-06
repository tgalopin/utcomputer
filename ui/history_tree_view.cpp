#include "history_tree_view.h"

HistoryTreeView::HistoryTreeView(BaseObjectType *treeview, const Glib::RefPtr<Gtk::Builder> &builder) :
    Gtk::TreeView(treeview), builder(builder) {
    refTreeModel = Gtk::ListStore::create(columns);
    set_model(refTreeModel);
    this->append_column("command", columns.col_command);
    nbAff = 0;
}

void HistoryTreeView::update(string command) {
    if (nbAff == 15) {
        refTreeModel = Gtk::ListStore::create(columns);
        set_model(refTreeModel);
        nbAff = 0;
    }

    Gtk::TreeModel::Row row = *(refTreeModel->append());
    row[columns.col_command] = command;
    nbAff++;
}
