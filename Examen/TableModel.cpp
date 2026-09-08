#include "TableModel.h"
#include <QString>

int TableModel::rowCount(const QModelIndex& parent)const {
	return tasks.size();
}

int TableModel::columnCount(const QModelIndex& parent)const {
	return 4;
}

QVariant TableModel::data(const QModelIndex& index, int role) const {
	if (role != Qt::DisplayRole) {
		return QVariant{};
	}
	//QVariant{} este o varianta goala-nu are nicio valoare


	if (!index.isValid()) {
		return QVariant{};
	}

	const Task& task = tasks[index.row()];

	if (index.column() == 0) {
		return task.getid();
	}

	if (index.column() == 1) {
		return QString::fromStdString(task.getdescriere());
	}

	if (index.column() == 2) {
		return QString::fromStdString(task.getstare());
	}

	if (index.column() == 3) {
		return task.getProgramatori().size();
	}
	return QVariant{};
}


QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
	if (role != Qt::DisplayRole) {
		return QVariant{};
	}

	if (orientation == Qt::Horizontal) {
		if (section == 0) {
			return "Id";
		}

		if (section == 1) {
			return "Descriere";
		}

		if (section == 2) {
			return "Stare";
		}

		if (section == 3) {
			return "Nr programatori asignati";
		}

	}

	return QVariant{};
}

//actualizeaza tabelul cand se schimba lista
void TableModel::setTasks(const vector<Task>& TasksNoi) {
	beginResetModel();
	this->tasks = TasksNoi;
	endResetModel();
}