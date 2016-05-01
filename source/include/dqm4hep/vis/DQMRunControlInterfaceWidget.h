  /// \file DQMRunControlInterfaceWidget.h
/*
 *
 * DQMRunControlInterfaceWidget.h header template automatically generated by a class generator
 * Creation date : sam. avr. 30 2016
 *
 * This file is part of DQM4HEP libraries.
 * 
 * DQM4HEP is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * based upon these libraries are permitted. Any copy of these libraries
 * must include this copyright notice.
 * 
 * DQM4HEP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with DQM4HEP.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * @author Remi Ete
 * @copyright CNRS , IPNL
 */


#ifndef DQMRUNCONTROLINTERFACEWIDGET_H
#define DQMRUNCONTROLINTERFACEWIDGET_H

// -- dqm4hep headers
#include "dqm4hep/DQM4HEP.h"
#include "dqm4hep/DQMDimRunControlClient.h"
#include "dqm4hep/vis/DQMLoggerWidget.h"

// -- qt headers
#include <QMainWindow>
#include <QGroupBox>
#include <QPushButton>
#include <QSpinBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QTableWidget>
#include <QHeaderView>
#include <QLabel>
#include <QTimer>

namespace dqm4hep
{

/** DQMRunControlInterfaceWidget class
 */
class DQMRunControlInterfaceWidget : public QMainWindow, public DQMRunListener
{
	Q_OBJECT

public:
	/** Constructor
	 */
	DQMRunControlInterfaceWidget();

	/** Detructor
	 */
	~DQMRunControlInterfaceWidget();

    /** Set the run control name.
     *  Disconnect from current client and reconnect to new client
     *  if names are different
	 */
    void setRunControlName(const std::string &name);

    /** Get the current run control client name
	 */
    std::string getRunControlName() const;

    /** Get the detector name of the current run
	 */
    std::string getDetectorName() const;

    /** Get the current run description
	 */
    std::string getDescription() const;

    /** Get the start time of the current run in h:m:s string format.
	 */
    std::string getStartTime() const;

    /** Get the elapsed time from start of run
	 */
    std::string getElapsedTime() const;

    /** Get the run control status (running or stopped) as a string
	 */
    std::string getStatus() const;

    /** Get the current run parameters
     */
    DQMParameters getRunParameters() const;

    /** Get the current run number
	 */
    int getRunNumber() const;

private:
    // call backs from run listener
	void onStartOfRun(DQMRun *const pRun);
	void onEndOfRun(const DQMRun *const pRun);

signals:
	/** Qt signal emitted when a run starts.
	 *  The started run object is accessed from the client interface
	 */
	void onStartOfRun();

	/** Qt signal emitted when a run ends.
	 *  The started run object is accessed from the client interface
	 */
	void onEndOfRun();

public slots:
	/**
	 */
	void importFile(const std::string &fileName);

	/**
	 */
	void exportFile(const std::string &fileName);

private slots:
	/**
	 */
	void importFile();

	/**
	 */
	void exportFile();

	/**
	 */
	void fillCurrentRunInfo();

	/**
	 */
	void sendStartOfRun();

	/**
	 */
	void sendEndCurrentRun();

    /** Add row to Table Widget
	 */
    void addNewRow();

    /** Add row to Table Widget
	 */
    void deleteRow();

    /**
     */
    void updateElapsedTime();

    /** Tidy start/stop run button state
     */
    void tidyButtonState();

private:
    /**
     */
    void setWindowTitle();

private:
    QGroupBox                        *m_pRunActionGroupBox;
    QLineEdit                        *m_pDetectorNameEdit;
    QTextEdit                        *m_pRunDescriptionTextEdit;
    QTableWidget                     *m_pRunParametersTableWidget;
    QPushButton                      *m_pAddParameterButton;
    QPushButton                      *m_pDeleteParameterButton;
    QPushButton                      *m_pStartOfRunButton;
    QPushButton                      *m_pEndOfRunButton;
    QSpinBox                         *m_pRunNumberSpinBox;

    QLabel                           *m_pRunNumberLabel;
    QLabel                           *m_pRunStateLabel;
    QLabel                           *m_pRunStartTimeLabel;
    QLabel                           *m_pRunElapsedTimeLabel;

    QTimer                            m_elapsedTimeTimer;

    DQMDimRunControlClient           *m_pRunControlClient;

    DQMLoggerWidget                  *m_pLogger;
}; 

} 

#endif  //  DQMRUNCONTROLINTERFACEWIDGET_H