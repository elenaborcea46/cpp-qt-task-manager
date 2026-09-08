#pragma once

#include <QAbstractTableModel>
#include <vector>

#include "Task.h"
#include "Service.h"

using std::vector;

class TableModel :public QAbstractTableModel {
private:
	vector<Task> tasks;

	Service& srv;
public:
	TableModel(const vector<Task>& tasks, Service& srv) :tasks{ tasks }, srv{ srv } {}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override;

	int columnCount(const QModelIndex& parent = QModelIndex()) const override;

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

	void setTasks(const vector<Task>& tasksNoi);

};