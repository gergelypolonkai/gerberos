/* Gerberos - Kerberos GLib bindings
 *
 * Copyright (C) 2009 Gergely Polonkai
 *
 */

#include <krb5.h>
#include <glib.h>

#include "gkrb5context.h"

#undef g_krb5_context

G_DEFINE_TYPE(GKrb5Context, g_krb5_context, G_TYPE_OBJECT);

struct _GKrb5ContextPrivate {
	krb5_context kerberos_context;

	GMainContext *context;
};

static void
g_krb5_context_set_property (GObject *object, guint prop_id, const GValue *value, GParamSpec *pspec)
{
	GKrb5Context *kerberos_context;

	kerberos_context = G_KRB5_CONTEXT(object);

	switch (prop_id)
	{
		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
			break;
	}
}

static void
g_krb5_context_get_property (GObject *object, guint prop_id, GValue *value, GParamSpec *pspec)
{
	switch (prop_id)
	{
		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
			break;
	}
}

static void
g_krb5_context_finalize (GObject *object)
{
	GKrb5Context *kerberos_context;

	kerberos_context = G_KRB5_CONTEXT(object);

	if (kerberos_context->priv->context)
		g_main_context_unref(kerberos_context->priv->context);

	G_OBJECT_CLASS(g_krb5_context_parent_class)->finalize(object);
}

static void
g_krb5_context_dispose(GObject *object)
{
	GKrb5Context *kerberos_context;
	GKrb5ContextPrivate *priv;

	kerberos_context = G_KRB5_CONTEXT(object);
	priv = kerberos_context->priv;

	krb5_free_context(priv->kerberos_context);

	G_OBJECT_CLASS(g_krb5_context_parent_class)->dispose(object);
}

static void
g_krb5_context_class_init(GKrb5ContextClass *klass)
{
	GObjectClass *object_class;

	g_type_class_add_private(klass, sizeof(GKrb5ContextPrivate));

	object_class = G_OBJECT_CLASS(klass);
	object_class->finalize = g_krb5_context_finalize;
	object_class->dispose = g_krb5_context_dispose;
	object_class->get_property = g_krb5_context_get_property;
	object_class->set_property = g_krb5_context_set_property;
}

static void
g_krb5_context_init(GKrb5Context *kerberos_context)
{
	kerberos_context->priv = G_TYPE_INSTANCE_GET_PRIVATE(kerberos_context, G_TYPE_KRB5_CONTEXT, GKrb5ContextPrivate);
	kerberos_context->priv->context = g_main_context_get_thread_default();
}

static void
g_krb5_context_constructor(GType gtype, guint n_properties, GObjectConstructParam *properties)
{
	GObject *object;
	GObjectClass *parent_class;
	GKrb5ContextPrivate *priv;
	GKrb5Context *kerberos_context;

	krb5_error_code libkrb_error;

	parent_class = G_OBJECT_CLASS(g_krb5_context_parent_class);
	object = parent_class->constructor(gtype, n_properties, properties);

	kerberos_context = G_KRB5_CONTEXT(object);
	priv = kerberos_context->priv;

	libkrb_error = krb5_init_context(&(priv->kerberos_context));
}

