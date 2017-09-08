/******************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  sweepplot Plugin
 * Author:   Sean D'Epagnier
 *
 ***************************************************************************
 *   Copyright (C) 2016 by Sean D'Epagnier                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 ***************************************************************************
 */

#include "SweepPlotUI.h"

class SweepPlotDialog;

class PlotConfigurationDialog: public PlotConfigurationDialogBase
{
public:
    PlotConfigurationDialog(wxWindow* parent, SweepPlotDialog &m_dialog, int index);
    ~PlotConfigurationDialog();

    void OnPDS( wxCommandEvent& event );
    void OnPlotChange(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    int PlotMinHeight() { return m_sPlotMinHeight->GetValue(); }

    static bool ShowTitleBar(int index);

private:
    SweepPlotDialog &m_SweepPlotDialog;
    struct cbState {
       cbState(wxCheckBox *a, wxString n) : cb(a), name(n) { }
        wxCheckBox *cb;
        wxString name;
    };

    std::list<cbState> m_cbStates;
};