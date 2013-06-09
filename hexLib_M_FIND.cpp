#include "wx_pch.h"
#include "hexLib_main.h"
M_FIND::M_FIND( void )
{
	find_p	 = null;
	out__p	 = null;
	edit_g	 = null;
	find_dd	 = NULL;
	type_dd	 = NULL;
	ram__dd	 = NULL;
	cmp__spb = NULL;
	max__spb = NULL;
	min__spb = NULL;
	cmp__txt = NULL;
	max__txt = NULL;
	min__txt = NULL;
	m_cmpMax = 0u;
	m_cmp	 = 0u;
	m_max	 = 0u;
	m_min	 = 0u;
	int i, j, l = 16, q;
	for ( q = 0; q < HEX_QCOUNT; ++q )
	{
		for ( i = 0; i < hexA_COUNT; ++i )
		{
			a_cb[ q ][ i ] = null;
			a_txt[ q ][ i ] = null;
			m_a[ q ][ i ] = 0uLL;
		}
		for ( i = 0; i < hexT_COUNT; ++i )
		{
			v_cb[ q ][ i ] = null;
			v_txt[ q ][ i ] = null;
			for ( j = 0; j < l; ++j )
			{
				m_v[ q ][ i ][ j ] = 0u;
			}
		}
	}
}
// Compare Objects
void M_FIND::cmp__spb_onspinH( wxSpinEvent &event )
{
	if ( m_cmp < m_cmpMax )
		++m_cmp;
	cmp__txt->ChangeValue( zxItoa( m_cmp + 1 ).data() );
	event.Skip();
}
void M_FIND::cmp__spb_onspinE( wxSpinEvent &event )
{
	if ( m_cmp > 0 )
		--m_cmp;
	cmp__txt->ChangeValue( zxItoa( m_cmp + 1 ).data() );
	event.Skip();
}
void M_FIND::cmp__txt_onchange( wxCommandEvent &event )
{
	m_cmp = ( zxAtoi( cmp__txt->GetValue().data() ) & 0xFFFF );
	if ( m_cmp > m_cmpMax )
		m_cmp = m_cmpMax;
	Text txt;
	txt.Printf( wxT("%01u"), m_cmp + 1u );
	cmp__txt->ChangeValue( txt );
	event.Skip();
}
// Max Bytes Objects
void M_FIND::max_check( bool fromMinCheck )
{
	if ( m_max < m_min && !fromMinCheck )
	{
		m_min = m_max;
		min_check( true );
	}
	if ( m_max < m_min )
		m_max = m_min;
	else if ( m_max > 16u )
		m_max = 16u;
	max__txt->ChangeValue( zxUtoa( m_max ).data() );
}
void M_FIND::max__spb_onspinH( wxSpinEvent &event )
{
	++m_max;
	max_check();
	event.Skip();
}
void M_FIND::max__spb_onspinE( wxSpinEvent &event )
{
	--m_max;
	max_check();
	event.Skip();
}
void M_FIND::max__txt_onchange( wxCommandEvent &event )
{
	m_max = ( zxAtou( max__txt->GetValue().data() ) & 0xFF );
	max_check();
	event.Skip();
}
// Min Bytes Objects
void M_FIND::min_check( bool fromMaxCheck )
{
	if ( m_min > m_max && !fromMaxCheck )
	{
		m_max = m_min;
		max_check( true );
	}
	if ( m_min > m_max )
		m_min = m_max;
	else if ( m_min == 0u )
		m_min = 1u;
	min__txt->ChangeValue( zxUtoa( m_min ).data() );
}
void M_FIND::min__spb_onspinH( wxSpinEvent &event )
{
	++m_min;
	min_check();
	event.Skip();
}
void M_FIND::min__spb_onspinE( wxSpinEvent &event )
{
	--m_min;
	min_check();
	event.Skip();
}
void M_FIND::min__txt_onchange( wxCommandEvent &event )
{
	m_min = ( zxAtoi( min__txt->GetValue().data() ) & 0xFF );
	min_check();
	event.Skip();
}
// Other Objects
void M_FIND::find_dd__onchange( wxCommandEvent &event )
{
	int i = find_dd->GetSelection();
	if ( i < 0 )
	{
		i = hexQ_NOACT;
		find_dd->SetSelection( i );
	}
	m_find = i;
	bool e = !( i == hexQ_NOACT );
	cmp__txt->Enable( e );
	cmp__spb->Enable( e );
	event.Skip();
}