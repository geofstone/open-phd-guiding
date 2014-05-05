/*
*  Refine_DefMap.h
*  PHD Guiding
*
*  Created by Bruce Waddington in collaboration with Andy Galasso and David Ault
*  Copyright (c) 2014 Bruce Waddington
*  All rights reserved.
*
*  This source code is distributed under the following "BSD" license
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*    Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*    Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the
*     documentation and/or other materials provided with the distribution.
*    Neither the name of Craig Stark, Stark Labs nor the names of its
*     contributors may be used to endorse or promote products derived from
*     this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
*/

#ifndef REFINEDEFMAP_H_INCLUDED
#define REFINEDEFMAP_H_INCLUDED

class RefineDefMap : public wxDialog
{
    struct MiscInfo
    {
        wxString creationTime;
        wxString cameraName;
        wxString darkExposureTime;
        wxString darkCount;
        wxString lastHotFactor;
        wxString lastColdFactor;
    };

public:
    RefineDefMap(wxWindow* pParent);
    ~RefineDefMap();

private:
    DefectMapDarks darks;
    DefectMapBuilder builder;

    void FrameLayout();
    void GetBadPxCounts();
    wxGridCellCoords hotPixelLoc;
    wxGridCellCoords coldPixelLoc;
    wxGridCellCoords hotFactorLoc;
    wxGridCellCoords coldFactorLoc;
    wxGridCellCoords createTimeLoc;
    wxGridCellCoords manualPixelLoc;
    wxGrid *pInfoGrid;
    wxGrid *pStatsGrid;
    wxFlexGridSizer *pAdjustmentGrid;
    wxSlider *pHotSlider;
    wxSlider *pColdSlider;
    wxButton *pResetBtn;
    wxButton *pApplyBtn;
    wxButton *pAddDefectBtn;
    wxButton *pCancelBtn;
    wxStatusBar *pStatusBar;
    wxCheckBox *pRebuildDarks;
    wxCheckBox *pShowDetails;
    wxSizer *pVSizer;
    wxStaticBoxSizer *pInfoGroup;
    void GetMiscInfo(MiscInfo& info);
    void OnGenerate(wxCommandEvent& evt);
    void OnHotChange(wxScrollEvent& evt);
    void OnColdChange(wxScrollEvent& evt);
    void OnAddDefect(wxCommandEvent& evt);
    void OnReset(wxCommandEvent& evt);
    void OnClose(wxCloseEvent& evt);
    void OnDetails(wxCommandEvent &ev);
    void Recalc();
    void ApplyNewMap();
    void ShowStatus(const wxString& msg, bool appending);
    wxString DefectMapTimeString();
    void GetBaselineStats();
    bool RebuildMasterDarks();
    void ShowDetailGroup(bool visible);
    long initHotFactor;
    long initColdFactor;
    int manualPixelCount = 0;
    DECLARE_EVENT_TABLE()
};

#endif REFINEDEFMAP_H_INCLUDED